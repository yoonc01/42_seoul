/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:26:52 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/08 16:27:32 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *) s1;
	u2 = (unsigned char *) s2;
	while (0 < n)
	{
		if (*u1 != *u2 || *u1 == '\0' || *u2 == '\0')
		{
			if (*u1 > *u2)
				return (1);
			else if (*u1 < *u2)
				return (-1);
			else
				return (0);
		}
		u1++;
		u2++;
		n--;
	}
	return (0);
}
