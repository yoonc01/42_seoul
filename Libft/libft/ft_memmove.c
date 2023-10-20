/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:23:56 by yunhyojun         #+#    #+#             */
/*   Updated: 2023/10/15 19:48:44 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lower(char *d, char *s, size_t len)
{
	while (0 < len)
	{
		*d = *s;
		d++;
		s++;
		len--;
	}
}

static void	greater(char *d, char *s, size_t len)
{
	while (0 < len)
	{
		*d = *s;
		d--;
		s--;
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (dst == 0 && src == 0)
		return (0);
	d = (char *) dst;
	s = (char *) src;
	if (d <= s)
		lower(d, s, len);
	else
	{
		d = d + len - 1;
		s = s + len - 1;
		greater(d, s, len);
	}
	return (dst);
}
