/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:39:39 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/03/28 20:29:59 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	check;

	str = (unsigned char *) s;
	check = (unsigned char) c;
	while (0 < n)
	{
		if (*str == check)
			return ((void *) str);
		str++;
		n--;
	}
	return (0);
}
