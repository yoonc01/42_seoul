/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:17:24 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/17 11:06:18 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = (char *) malloc(len1 + len2 + 1);
	if (ans == 0)
		return (0);
	ft_strlcpy(ans, s1, len1 + 1);
	ft_strlcat(ans, s2, len1 + len2 + 1);
	return (ans);
}
