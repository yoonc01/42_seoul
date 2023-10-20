/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:05:20 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/09 14:02:08 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	in_set(char *str, char *charset)
{
	while (*charset)
	{
		if (*str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	is_word;
	int	cnt;

	is_word = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (is_word == 0 && !in_set(str, charset))
		{
			cnt++;
			is_word = 1;
		}
		else if (in_set(str, charset))
			is_word = 0;
		str++;
	}
	return (cnt);
}

int	word_size(char *str, char *charset)
{
	int	size;

	size = 0;
	while (*str != '\0')
	{
		if (in_set(str, charset))
			break ;
		size++;
		str++;
	}
	return (size);
}

void	copy(char *dest, char *src, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		*dest = *src;
		dest++;
		src++;
		idx++;
	}
	*dest = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		num;
	int		size;
	int		idx;
	char	**ans;

	num = count_words(str, charset);
	idx = 0;
	ans = (char **)malloc(sizeof(char *) * (num + 1));
	ans[num] = 0;
	while (*str != '\0')
	{
		if (!in_set(str, charset))
		{
			size = word_size(str, charset);
			ans[idx] = malloc(sizeof(char) * (size + 1));
			copy(ans[idx], str, size);
			idx++;
			str = str + size;
		}
		else
			str++;
	}
	return (ans);
}
