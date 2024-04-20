/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:31:05 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/20 12:31:06 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	const char	*eos;

	eos = str;
	while (*eos != '\0')
		eos++;
	return (eos - str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (src[len] != '\0' && len + 1 < dstsize)
	{
		dst[len] = src[len];
		len++;
	}
	if (0 != dstsize)
		dst[len] = '\0';
	while (src[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (dst == 0 && dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && d_len + 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (d_len + s_len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ans;

	len = ft_strlen(s1);
	ans = (char *) malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	ft_strlcpy(ans, s1, len + 1);
	return (ans);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = (char *) malloc(len1 + len2 + 1);
	if (ans == 0)
		return (0);
	ft_strlcpy(ans, s1, len1 + 1);
	ft_strlcat(ans, s2, len1 + len2 + 1);
	return (ans);
}
