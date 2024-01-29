/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:18:55 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/01/26 19:51:04 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*read_line(int fd, char *save)
{
	ssize_t	size;
	char	*buffer;
	char	*temp;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	size = 1;
	while (ft_strchr(save, '\n') == 0 && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(buffer);
			free(save);
			return (0);
		}
		buffer[size] = '\0';
		temp = ft_strjoin(save, buffer);
		free(save);
		save = temp;
	}
	free(buffer);
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
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(save);
		return (0);
	}
	if (save == 0)
	{
		save = ft_strdup("");
		if (save == 0)
			return (0);
	}
	save = read_line(fd, save);
	if (save == 0)
		return (0);
	temp = get_new_save(save);
	ans = get_new_line(save);
	free(save);
	save = temp;
	return (ans);
}
