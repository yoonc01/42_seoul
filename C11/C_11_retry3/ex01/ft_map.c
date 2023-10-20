/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:38:16 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/09 19:41:37 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	idx;

	arr = (int *)malloc(sizeof(int) * length);
	idx = 0;
	while (idx < length)
	{
		arr[idx] = (*f)(tab[idx]);
		idx++;
	}
	return (arr);
}
