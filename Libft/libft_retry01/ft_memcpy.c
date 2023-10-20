/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:42:43 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/17 11:13:49 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
