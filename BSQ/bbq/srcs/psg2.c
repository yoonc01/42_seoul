/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:46:59 by gko               #+#    #+#             */
/*   Updated: 2023/09/13 23:20:59 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

int	first_line(char *str_map, t_map *map)
{
	int	end;
	int	i;

	end = 0;
	i = 0;
	while (str_map[end] != '\0' && str_map[end] != '\n')
			end++;
	if (end < 4)
		return (0);
	map -> fill = str_map[end - 1];
	map -> obs = str_map[end - 2];
	map -> empty = str_map[end - 3];
	map -> lines = ft_atoi(str_map, (end - 3));
	if (map -> lines <= 0 || map -> obs == map -> empty || \
			map -> obs == map -> fill || map -> fill == map -> empty)
		return (0);
	map -> length = get_line_length(str_map + end + 1);
	return (1);
}

int	map_ok(char *str_map, t_map *map)
{
	int	char_count;
	int	line_count;

	line_count = 0;
	while (*str_map != '\n')
		str_map++;
	str_map++;
	while (*str_map != '\0')
	{
		char_count = 0;
		while (*str_map != '\n')
		{
			if (*str_map != map -> obs && *str_map != map -> empty)
				return (0);
			char_count++;
			str_map++;
		}
		if (char_count != map -> length)
			return (0);
		line_count++;
		str_map++;
	}
	if (line_count != map -> lines)
		return (0);
	return (1);
}

char	*process_file(int fd, int filesize)
{
	char	*content;
	int		size;
	int		i;

	i = 0;
	content = malloc(sizeof(char) * (filesize + 1));
	if (content == 0)
		return (0);
	size = 1;
	while (0 < size)
	{
		size = read(fd, content + i, 1024);
		i = i + size;
	}
	close(fd);
	content[filesize] = 0;
	return (content);
}
