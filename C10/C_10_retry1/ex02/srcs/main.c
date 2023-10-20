/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:02:55 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/14 15:11:07 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

t_cmd	get_cmd(int ac, char **av)
{
	t_cmd		cmd;

	cmd.idx = -1;
	cmd.len = 0;
	cmd.read = 1;
	if (ac < 3 || (ft_strcmp(av[1], "-c") == 0 && ac < 4))
	{
		cmd.read = 0;
		if (ac == 2)
			cmd.len = ft_atoi(av[1] + 2);
		else
			cmd.len = ft_atoi(av[2]);
		return (cmd);
	}
	if (ft_strcmp(av[1], "-c") == 0)
	{
		cmd.idx = 3;
		cmd.len = ft_atoi(av[2]);
	}
	else
	{
		cmd.idx = 2;
		cmd.len = ft_atoi(av[1] + 2);
	}
	return (cmd);
}

int	main(int ac, char **av)
{
	t_cmd	cmd;
	int		fd;
	int		fileindex;

	cmd = get_cmd(ac, av);
	fileindex = cmd.idx;
	if (cmd.read == 0)
		ft_tail(cmd.len, 0);
	while (fileindex < ac && fileindex != -1)
	{
		fd = open(av[fileindex], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr(basename(av[0]));
			write(1, ": ", 2);
			ft_putstr(av[fileindex]);
			write(1, ", ", 2);
			ft_putstr(strerror(2));
			write(1, "\n", 1);
			close(fd);
			return (0);
		}
		if (fileindex != cmd.idx)
			write(1, "\n", 1);
		if (cmd.idx < ac)
		{
			write(1, "==> ", 4);
			ft_putstr(av[fileindex]);
			write(1, " <==\n", 5);
			ft_tail(cmd.idx, fd);
		}
		fileindex++;
	}
	return(0);
}
