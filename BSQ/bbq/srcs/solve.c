/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:26:34 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/13 23:31:50 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int	in_range(int r, int c, t_point max_pos, int max)
{
	if (max_pos.c - max + 1 <= c && c <= max_pos.c)
	{
		if (max_pos.r - max + 1 <= r && r <= max_pos.r)
			return (1);
		return (0);
	}
	return (0);
}

void	print_map(t_map *map, t_point max_pos, int max)
{
	int	c;
	int	r;

	r = 0;
	while (r < map -> lines)
	{
		c = 0;
		while (c < map->length)
		{
			if (in_range(r, c, max_pos, max))
				ft_putchar(map -> fill);
			else
			{
				if (map -> map[r][c] == 0)
					ft_putchar(map -> obs);
				else
					ft_putchar(map -> empty);
			}
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

void	solve(t_map *map, int max)
{
	int		r;
	int		c;
	t_point	max_pos;

	r = 0;
	while (r < map -> lines)
	{
		c = 0;
		while (c < map -> length)
		{
			if (map->map[r][c] == 1 && 1 <= r && 1 <= c)
				map->map[r][c] = min(map->map[r - 1][c - 1], \
						map->map[r - 1][c], map->map[r][c - 1]) + 1;
			if (map->map[r][c] > max)
			{
				max = map->map[r][c];
				max_pos.c = c;
				max_pos.r = r;
			}
			c++;
		}
		r++;
	}
	print_map(map, max_pos, max);
}
