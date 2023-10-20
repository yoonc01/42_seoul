/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:03:27 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/08 14:56:06 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	check;

	check = (char) c;
	while (*s != '\0')
	{
		if (*s == check)
			return ((char *) s);
		s++;
	}
	if (check == 0)
		return ((char *) s);
	return (0);
}
