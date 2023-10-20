/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:12:00 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/11 16:59:33 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	char		check;

	last = 0;
	check = (char) c;
	while (*s != '\0')
	{
		if (*s == check)
			last = s;
		s++;
	}
	if (check == 0)
		return ((char *) s);
	return ((char *) last);
}
