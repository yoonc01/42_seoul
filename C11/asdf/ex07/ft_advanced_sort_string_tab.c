/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:16:19 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/10 19:23:40 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	total_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	i = 0;
	len = total_len(tab);
	while (i < len)
	{
		j = 1;
		while (j < len - i)
		{
			if ((*cmp)(tab[j - 1], tab[j]) > 0)
			{
				temp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
