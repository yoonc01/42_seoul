/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:04:55 by yunhyojun         #+#    #+#             */
/*   Updated: 2023/10/15 20:07:04 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ans;

	len = ft_strlen(s1);
	ans = (char *) malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	ft_memcpy(ans, s1, len + 1);
	return (ans);
}
