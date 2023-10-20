/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:36:10 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/24 14:42:39 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	idx;
	int	temp;

	idx = 0;
	while (idx < (size - 1) / 2)
	{
		temp = tab[idx];
		tab[idx] = tab[size - 1 - idx];
		tab[size - 1 - idx] = temp;
		idx++;
	}
}
