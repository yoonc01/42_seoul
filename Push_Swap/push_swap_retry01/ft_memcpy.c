/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:42:43 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/13 11:18:49 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
