/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:24:24 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/11 16:29:17 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <fcntl.h>

void	readfile(char *str)
{
	char	buff[1];
	int		fd;
	int		size;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
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
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
		readfile(av[1]);
}
