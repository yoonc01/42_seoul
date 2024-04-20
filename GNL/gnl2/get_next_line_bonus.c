/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:30:52 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/20 12:42:21 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	check;

	check = (char) c;
	while (*s != '\0')
	{
		if (*s == check)
			return ((char *) s);
		s++;
	}
	if (check == 0)
		return ((char *) s);
	return (0);
}

char	*read_line(int fd, char *buffer, char *save)
{
	ssize_t	size;
	char	*temp;

	size = 1;
	while (ft_strchr(save, '\n') == 0 && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(save);
			return (0);
		}
		buffer[size] = '\0';
		temp = ft_strjoin(save, buffer);
		free(save);
		if (temp == 0)
			return (0);
		save = temp;
	}
	return (save);
}

char	*get_new_save(char *save)
{
	char	*next_ptr;
	char	*new_save;

	if (save == 0)
		return (0);
	next_ptr = ft_strchr(save, '\n');
	if (next_ptr == 0)
		return (0);
	new_save = ft_strdup(next_ptr + 1);
	if (new_save == 0)
		return (0);
	return (new_save);
}

char	*get_new_line(char *save)
{
	char	*next_ptr;
	char	*ans;

	if (*save == 0)
		return (0);
	next_ptr = ft_strchr(save, '\n');
	if (next_ptr == 0)
	{
		ans = ft_strdup(save);
		if (ans == 0)
			return (0);
		return (ans);
	}
	*(next_ptr + 1) = '\0';
	ans = ft_strdup(save);
	if (ans == 0)
		return (0);
	return (ans);
}

char	*get_next_line(int fd)
{
	char		*ans;
	char		*temp;
	char		*buffer[OPEN_MAX];
	static char	*save[OPEN_MAX];

	if (fd < 0)
		return (0);
	if (save[fd] == 0)
	{
		save[fd] = ft_strdup("");
		if (save[fd] == 0)
			return (0);
	}
	buffer[fd] = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer[fd] == 0)
		return (0);
	save[fd] = read_line(fd, buffer[fd], save[fd]);
	free(buffer[fd]);
	if (save[fd] == 0)
		return (0);
	temp = get_new_save(save[fd]);
	ans = get_new_line(save[fd]);
	free(save[fd]);
	save[fd] = temp;
	return (ans);
}
