/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:05:20 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/15 23:17:24 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

static int	count_words(char *str)
{
	int	is_word;
	int	cnt;

	is_word = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (is_word == 0 && !is_space(*str))
		{
			cnt++;
			is_word = 1;
		}
		else if (is_space(*str))
			is_word = 0;
		str++;
	}
	return (cnt);
}

static int	word_size(char *str)
{
	int	size;

	size = 0;
	while (*str != '\0' && !is_space(*str))
	{
		size++;
		str++;
	}
	return (size);
}

static char	*copy(char *str, int size)
{
	char	*ans;

	ans = (char *) malloc(sizeof(char) * (size + 1));
	if (ans == 0)
		exit(EXIT_FAILURE);
	ans[size] = '\0';
	ft_memcpy(ans, str, size);
	return (ans);
}

char	**split(char *s)
{
	int		idx;
	int		num;
	int		size;
	char	**ans;

	idx = 0;
	num = count_words(s);
	ans = (char **)malloc(sizeof(char *) * (num + 1));
	if (ans == 0)
		exit(EXIT_FAILURE);
	ans[num] = 0;
	while (*s != '\0')
	{
		if (!is_space(*s))
		{
			size = word_size(s);
			ans[idx] = copy(s, size);
			s = s + size;
			idx++;
		}
		else
			s++;
	}
	return (ans);
}
