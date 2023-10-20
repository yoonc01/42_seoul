/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:11:39 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/10 16:11:39 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	else
		return (-1);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[min_idx], tab[j]) > 0)
				min_idx = j;
			j++;
		}
		temp = tab[i];
		tab[i] = tab[min_idx];
		tab[min_idx] = temp;
		i++;
	}
}
