/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:39:39 by yunhyojun         #+#    #+#             */
/*   Updated: 2023/10/08 14:45:53 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*str;
	unsigned char	check;

	cnt = 0;
	str = (unsigned char *) s;
	check = (unsigned char) c;
	while (cnt < n)
	{
		if (*str == check)
			return ((void *) str);
		cnt++;
		str++;
	}
	return (0);
}
