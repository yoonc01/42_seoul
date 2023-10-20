/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:20:47 by yunhyojun         #+#    #+#             */
/*   Updated: 2023/10/15 20:22:49 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	while (*set != 0)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*go_eos(char const *s1)
{
	while (*s1 != '\0')
		s1++;
	return ((char *) s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ans;

	start = (char *) s1;
	end = go_eos(s1);
	while (in_set(set, *start))
		start++;
	if (start == end)
	{
		ans = (char *)malloc (sizeof(char) * 1);
		if (ans == 0)
			return (0);
		*ans = '\0';
		return (ans);
	}
	end--;
	while (start < end && in_set(set, *end))
		end--;
	ans = (char *) malloc (sizeof(char) * (end - start + 2));
	if (ans == 0)
		return (0);
	ans[end - start + 1] = '\0';
	ft_memcpy(ans, start, end - start + 1);
	return (ans);
}
