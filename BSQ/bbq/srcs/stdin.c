/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:12:07 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/13 23:32:09 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

char	*process_file_stdin(void)
{
	char	buffer[1024];
	int		size;
	char	*content;

	content = malloc(sizeof(char) * 1);
	if (content == 0)
		return (0);
	content[0] = 0;
	size = 1;
	while (0 < size)
	{
		size = read(0, buffer, 1024);
		if (size > 0)
			content = strncat_malloc(content, buffer, size);
	}
	return (content);
}

t_map	*map_stdin(void)
{
	t_map	*map;
	char	*str_map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == 0)
		return (0);
	str_map = process_file_stdin();
	if (first_line(str_map, map) && map_ok(str_map, map))
		map -> map = str_to_matrix(str_map, map);
	else
		return (0);
	return (map);
}

void	do_stdin(void)
{
	t_map	*map;

	map = map_stdin();
	if (map == 0)
		write(2, "map error\n", 10);
	else
		solve(map, 0);
}
