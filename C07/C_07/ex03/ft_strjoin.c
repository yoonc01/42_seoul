/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:17:24 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/09 16:51:25 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	total_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size - 1)
	{
		len = len + str_len(strs[i]) + str_len(sep);
		i++;
	}
	len = len + str_len(strs[i]) + 1;
	return (len);
}

char	*copy(char *dest, char *src, char *sep)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	while (*sep != '\0')
	{
		*dest = *sep;
		dest++;
		sep++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*ans;
	char	*next;

	i = 0;
	len = total_len(size, strs, sep);
	ans = (char *)malloc(sizeof(char) * len);
	if (ans == 0)
		return (0);
	next = ans;
	while (i < size - 1)
	{
		next = copy(next, strs[i], sep);
		i++;
	}
	copy(next, strs[i], "\0");
	return (ans);
}
