/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:16:19 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/10 16:11:51 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		min_idx;
	char	*temp;

	i = 0;
	while (tab[i] != 0)
	{
		min_idx = i;
		j = i + 1;
		while (tab[j] != 0)
		{
			if ((*cmp)(tab[min_idx], tab[j]) > 0)
				min_idx = j;
			j++;
		}
		temp = tab[i];
		tab[i] = tab[min_idx];
		tab[min_idx] = temp;
		i++;
	}
}
