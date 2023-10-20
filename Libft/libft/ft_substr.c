/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:06:30 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/15 15:27:57 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;

	if (ft_strlen(s) <= start)
	{
		ans = (char *)malloc(1);
		if (ans == 0)
			return (0);
		*ans = '\0';
		return (ans);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	ans = (char *)malloc(len + 1);
	if (ans == 0)
		return (0);
	ans[len] = '\0';
	ft_memcpy(ans, s + start, len);
	return (ans);
}
