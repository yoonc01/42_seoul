/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:51:29 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/13 22:40:54 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

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

int	count_rows(char *str, char *charset)
{
	int	is_row;
	int	cnt;

	is_row = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (is_row == 0 && !in_set(str, charset))
		{
			cnt++;
			is_row = 1;
		}
		else if (in_set(str, charset))
			is_row = 0;
		str++;
	}
	return (cnt);
}

int	row_size(char *str, char *charset)
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

void	copy(int *dest, char *src, t_map *map, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		if (*src == map -> obs)
			*dest = 0;
		else if (*src == map -> empty)
			*dest = 1;
		dest++;
		src++;
		idx++;
	}
}

int	**split(char *str, char *charset, t_map *map)
{
	int	num;
	int	size;
	int	idx;
	int	**ans;

	num = count_rows(str, charset);
	idx = 0;
	ans = (int **)malloc(sizeof(int *) * (num));
	ans[num] = 0;
	while (*str != '\0')
	{
		if (!in_set(str, charset))
		{
			size = row_size(str, charset);
			ans[idx] = (int *)malloc(sizeof(int) * (size));
			copy(ans[idx], str, map, size);
			idx++;
			str = str + size;
		}
		else
			str++;
	}
	return (ans);
}
