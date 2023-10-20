/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:43:40 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/15 20:22:08 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	idx;
	size_t	l;

	if (*to_find == '\0')
		return ((char *) str);
	if (len == 0)
		return (0);
	if (ft_strlen(str) == 0)
		return (0);
	idx = 0;
	l = ft_strlen(to_find);
	while (idx + l <= len)
	{
		if (ft_strncmp(str, to_find, l) == 0)
			return ((char *) str);
		str++;
		idx++;
	}
	return (0);
}
