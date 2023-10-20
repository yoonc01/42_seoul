/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:52:03 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/11 17:42:14 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	read_and_write(void)
{
	int		size;
	char	buff[512];

	size = 1;
	while (0 < size)
	{
		size = read(0, buff, 512);
		write(1, buff, size);
	}
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	readfile(char *str, char *program)
{
	char	buff[1];
	int		size;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(basename(program));
		write(1, ": ", 2);
		ft_putstr(str);
		write(1, ": ", 2);
		ft_putstr(strerror(2));
		write(1, "\n", 1);
		return ;
	}
	size = read(fd, buff, 1);
	while (0 < size)
	{
		write(1, buff, size);
		size = read(fd, buff, 1);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	int	file_ac;

	file_ac = 1;
	if (ac == 1)
		read_and_write();
	else
	{
		while (file_ac < ac)
		{
			if (av[file_ac][0] == '-')
				read_and_write();
			else
				readfile(av[file_ac], av[0]);
			file_ac++;
		}
	}
}
