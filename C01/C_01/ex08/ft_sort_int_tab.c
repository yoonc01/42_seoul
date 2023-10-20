/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:47:14 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/24 14:54:30 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx;
	int	min_idx;
	int	cmp_idx;
	int	temp;

	idx = 0;
	while (idx < size - 1)
	{
		min_idx = idx;
		cmp_idx = idx + 1;
		while (cmp_idx < size)
		{
			if (tab[cmp_idx] < tab[min_idx])
			{
				min_idx = cmp_idx;
			}
			cmp_idx++;
		}
		temp = tab[idx];
		tab[idx] = tab[min_idx];
		tab[min_idx] = temp;
		idx++;
	}
}
