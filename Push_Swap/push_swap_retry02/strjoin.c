/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:53:19 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/05/15 23:35:03 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *str)
{
	const char	*eos;

	eos = str;
	while (*eos != '\0')
		eos++;
	return (eos - str);
}

char	*strjoin(char *s1, char *s2)
{
	char	*ans;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = (char *) malloc(len1 + len2 + 2);
	if (ans == 0)
		exit(EXIT_FAILURE);
	ft_memcpy(ans, s1, len1);
	*(ans + len1) = ' ';
	ft_memcpy(ans + len1 + 1, s2, len2);
	ans[len1 + len2 + 1] = '\0';
	return (ans);
}
