/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:43:30 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/10 18:45:45 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	descend;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
		{
			if (i == 0)
				descend = 1;
			if (!descend)
				return (0);
		}
		else if ((*f)(tab[i], tab[i + 1]) < 0)
		{
			if (i == 0)
				descend = 0;
			if (descend)
				return (0);
		}
		i++;
	}
	return (1);
}
