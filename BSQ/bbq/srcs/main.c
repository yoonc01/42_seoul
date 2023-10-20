/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:13:35 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/13 23:28:02 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

int	main(int ac, char **av)
{
	int		idx;
	t_map	*map;

	idx = 1;
	if (ac == 1)
		do_stdin();
	else
	{
		while (idx < ac)
		{
			map = mapping(av[idx]);
			if (map != 0)
				solve(map, 0);
			else
				write(2, "map error\n", 10);
			if (idx < ac - 1)
				write(1, "\n", 1);
			idx++;
		}
	}
	return (0);
}
