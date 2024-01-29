/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:08:53 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/01/22 20:50:51 by hyoyoon          ###   ########.fr       */
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

char	*copy(char *dst, char *src)
{
	while (*src != 0)
	{
		*dst = *src;
		if (*src == '\n')
			return (dst + 1);
		dst++;
		src++;
	}
	return (dst);
}

size_t	total_len(t_list **lst)
{
	size_t	len;
	t_list	*list;
	char	*str;

	len = 0;
	list = *lst;
	while (list->next != 0)
	{
		len = len + BUFFER_SIZE;
		list = list->next;
	}
	str = list->content;
	while(*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*list_to_str(t_list **lst)
{
	size_t	len;
	char	*ans;
	char	*ptr;
	t_list	*list;

	len = total_len(lst);
	ans = malloc(sizeof(char) * (len + 1));
	ptr = ans;
	list = *lst;
	while (list->next != 0)
	{
		ptr = copy(ptr, list->content);
		list = list->next;
	}
	*ptr = '\0';
	return (ans);
}

int	process(int fd, char **ans, char **save, t_list **lst)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	size = read(fd, buffer, BUFFER_SIZE);
	if (size <= 0)
		return (0);
	while (size > 0)
	{
		buffer[size] = '\0';
		if (ft_strchr(buffer, '\n') != 0)
		{
			*save = ft_strdup(ft_strchr(buffer, '\n') + 1);
			if (save == 0)
				return (0);
			*ans = list_to_str(lst);
			if (ans == 0)
				return (0);
		}
		temp = ft_lstnew(buffer);
		ft_lstadd_back(temp);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (size < 0)
		return (0);
	

			

char	*get_next_line(int fd)
{
	ssize_t		size;
	char		*ans;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;

	if (save != 0)
	{
		temp = ft_lstnew(save);
		ft_lstadd_back(lst, temp);
		free(save);
		save = 0;
	}
	size = read(fd, buffer, BUFFER_SIZE);
	if (size <= 0)
		return (0);
	while (size > 0)
	{
		buffer[size] = '\0';
		if (ft_strchr(buffer, '\n') != 0)
		{
			save = ft_strdup(ft_strchr(buffer, '\n') + 1);
			if (save == 0)
				return (0);
			ans = list_to_str(lst);
			if (ans == 0)
				return (0);
			return (ans);
		}
		temp = ft_lstnew(buffer);
		ft_lstadd_back(temp);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (size < 0)
	{
		free_all(lst);
		return (0);
	}
	ans = list_to_str(lst);
	return (ans);
}
