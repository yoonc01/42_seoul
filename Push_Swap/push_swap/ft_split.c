/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:05:20 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/16 17:17:39 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char c)
{
	int	is_word;
	int	cnt;

	is_word = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (is_word == 0 && *str != c)
		{
			cnt++;
			is_word = 1;
		}
		else if (*str == c)
			is_word = 0;
		str++;
	}
	return (cnt);
}

static int	word_size(const char *str, char c)
{
	int	size;

	size = 0;
	while (*str != '\0')
	{
		if (*str == c)
			break ;
		size++;
		str++;
	}
	return (size);
}

static char	*copy(const char *str, int size)
{
	char	*ans;

	ans = (char *) malloc(sizeof(char) * (size + 1));
	if (ans == 0)
		return (0);
	ans[size] = '\0';
	ft_memcpy(ans, str, size);
	return (ans);
}

static char	**distribute(const char *s, char c, char **ans)
{
	int	idx;

	idx = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			ans[idx] = copy(s, word_size(s, c));
			s = s + word_size(s, c);
			if (ans[idx] == 0)
			{
				idx--;
				while (0 <= idx)
					free(ans[idx--]);
				free(ans);
				return (0);
			}
			idx++;
		}
		else
			s++;
	}
	return (ans);
}

char	**ft_split(const char *s, char c)
{
	int		num;
	char	**ans;

	num = count_words(s, c);
	ans = (char **)malloc(sizeof(char *) * (num + 1));
	if (ans == 0)
		return (0);
	ans[num] = 0;
	ans = distribute(s, c, ans);
	return (ans);
}
