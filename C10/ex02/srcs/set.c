/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:28:44 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 15:34:35 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h" 

void	init_set(char **set)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		set[i] = 0;
		i++;
	}
}

void	free_set(char **set)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		free(set[i]);
		i++;
	}
	free(set);
}

int	max_ten(int n)
{
	if (n < 10)
		return (n);
	return (10);
}
