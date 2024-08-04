/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:43:40 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/08/04 23:34:52 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	needle_len;

	idx = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	needle_len = ft_strlen(needle);
	if (needle_len > len)
		return (0);
	while (*haystack != '\0' && idx + needle_len <= len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *) haystack);
		haystack++;
		idx++;
	}
	return (NULL);
}
