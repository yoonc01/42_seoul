/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:02:18 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/13 21:00:21 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
