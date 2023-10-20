/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:39:50 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 19:53:57 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

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

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	char	*ans;
	char	*cat;

	cat = malloc((ft_strlen(dest) + ft_strlen(src) + 1) * sizeof(char));
	if (ans == 0)
		return (0);
	ans = cat;
	while (*dest != '\0')
	{
		*cat = *dest;
		cat++;
		dest++;
	}
	*cat = 0;
	while (*src != '\0')
	{
		*cat = *src;
		cat++;
		src++;
	}
	*cat = '\0';
	free(dest);
	return (ans);
}
