/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:56:28 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/06 17:06:52 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*ft_strdup(char *src)
{
	char	*newstr;
	char	*ans;
	int		len;

	len = str_len(src);
	newstr = (char *) malloc(sizeof(char) * (len + 1));
	if (newstr == 0)
		return (0);
	ans = newstr;
	while (*src != '\0')
	{
		*newstr = *src;
		newstr++;
		src++;
	}
	*newstr = *src;
	return (ans);
}
