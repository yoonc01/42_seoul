/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:39:44 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/06 13:57:03 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*str_copy(char *str)
{
	char	*arr;
	char	*for_return;

	arr = (char *)malloc(sizeof(char) * (str_len(str) + 1));
	if (arr == 0)
		return (0);
	for_return = arr;
	while (*str != '\0')
	{
		*arr = *str;
		str++;
		arr++;
	}
	*arr = *str;
	return (for_return);
}

void	add_data(int i_size, char *i_str, char *i_copy, t_stock_str *arr)
{
	arr->size = i_size;
	arr->str = i_str;
	arr->copy = i_copy;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*list;

	i = 0;
	list = (t_stock_str *)malloc(sizeof(t_stock_str) * ac);
	if (list == 0)
		return (0);
	while (i < ac)
	{
		if (str_copy(av[i]) == 0)
			return (0);
		add_data(str_len(av[i]), av[i], str_copy(av[i]), &list[i]);
		i++;
	}
	list[i].str = 0;
	return (list);
}
