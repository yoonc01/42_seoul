/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:00:39 by yunhyojun         #+#    #+#             */
/*   Updated: 2023/10/15 15:25:13 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;

	ans = (void *)malloc(size * count);
	if (ans == 0)
		return (0);
	ft_bzero(ans, count * size);
	return (ans);
}
