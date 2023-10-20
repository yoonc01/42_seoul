/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:09:13 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/13 21:00:35 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
