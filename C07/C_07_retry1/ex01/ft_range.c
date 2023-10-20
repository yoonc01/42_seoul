/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:01:33 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/09 20:40:56 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	*ans;

	if (min >= max)
		return (0);
	else
	{
		arr = (int *) malloc(sizeof(int) * (max - min));
		if (arr == 0)
			return (0);
		ans = arr;
		while (min < max)
		{
			*arr = min;
			arr++;
			min++;
		}
	}
	return (ans);
}
