/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:35:18 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/05/15 23:37:08 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dst == 0 && src == 0)
		exit(EXIT_FAILURE);
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
