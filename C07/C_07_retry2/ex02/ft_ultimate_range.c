/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:49 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/06 17:06:08 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;

	len = 0;
	if (max <= min)
	{
		range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (range == 0)
		return (-1);
	while (min < max)
	{
		range[0][len] = min;
		min++;
		len++;
	}
	return (len);
}
