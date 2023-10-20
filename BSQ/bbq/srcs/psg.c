/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:12:52 by gko               #+#    #+#             */
/*   Updated: 2023/09/14 00:39:33 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

char	*strncat_malloc(char *old, char *add, int n)
{
	char	*new;
	int		idx;
	int		old_len;

	old_len = ft_strlen(old);
	idx = 0;
	new = malloc(sizeof(char) * (old_len + n + 1));
	if (new == 0)
		return (0);
	while (old[idx] != '\0')
	{
		new[idx] = old[idx];
		idx++;
	}
	new[idx] = '\0';
	idx = 0;
	while (add[idx] != '\0' && idx < n)
	{
		new[old_len + idx] = add[idx];
		idx++;
	}
	new[old_len + idx] = '\0';
	return (new);
}

int	get_line_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

int	get_map_size(char *file)
{
	int		size;
	int		total_len;
	char	buff[128];
	int		fd;

	size = 1;
	total_len = 0;
	fd = open(file, O_RDONLY);
	while (0 < size)
	{
		size = read(fd, buff, 128);
		total_len = total_len + size;
	}
	return (total_len);
}

t_map	*mapping(char *file)
{
	t_map	*map;
	char	*str_map;
	int		fd;
	int		size;

	size = get_map_size(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map = (t_map *)(malloc(sizeof(t_map)));
	if (map == 0)
		return (0);
	str_map = process_file(fd, size);
	if (first_line(str_map, map) && map_ok(str_map, map))
		map -> map = str_to_matrix(str_map, map);
	else
		return (0);
	close(fd);
	return (map);
}
