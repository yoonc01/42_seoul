/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:09:18 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/14 15:22:44 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	else
		return (-1);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strncat(char *old, char *add, int n)
{
	int		i;
	int		old_len;
	char	*new;

	old_len = ft_strlen(old);
	new = (char *)malloc(sizeof(char) * (old_len + ft_strlen(add) + 1));
	if (new == 0)
		return (0);
	i = 0;
	while (old[i] != '\0')
	{
		new[i] = old[i];
		i++;
	}
	new[i] = 0;
	i = 0;
	while (add[i] != '\0' && i < n)
	{
		new[old_len + i] = add[i];
		i++;
	}
	new[old_len + i] = '\0';
	return (new);
}
