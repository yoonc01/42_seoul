/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:25:07 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/01/22 20:38:07 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*eos;

	eos = str;
	while (*eos != '\0')
		eos++;
	return (eos - str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dst == 0 && src == 0)
		return (0);
	d = (char *) dst;
	s = (char *) src;
	while (0 < n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ans;

	len = ft_strlen(s1);
	ans = (char *) malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	ft_memcpy(ans, s1, len + 1);
	return (ans);
}

t_list	*ft_lstnew(char *buffer)
{
	t_list	*new;
	int		idx;

	idx = 0;
	new = (t_list *) malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->content = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new->content == 0)
	{
		free(new);
		return (0);
	}
	copy(new->content, buffer);
	new->next = 0;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == 0)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = new;
	}
}
