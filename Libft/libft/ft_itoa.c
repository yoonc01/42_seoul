/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:48:40 by yunhyojun         #+#    #+#             */
/*   Updated: 2023/10/15 19:34:22 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	malloc_size(int nbr, int digit)
{
	int	size;

	size = (nbr <= 0);
	while (nbr)
	{
		nbr = nbr / digit;
		size++;
	}
	size++;
	return (size);
}

static void	ft_putnbr_base(int nbr, char *base, char *ans)
{
	int		digit;
	int		idx;

	digit = (int) ft_strlen(base);
	idx = malloc_size(nbr, digit) - 1;
	ans[idx--] = 0;
	if (nbr < 0)
	{
		while (1 <= idx)
		{
			ans[idx] = base[-(nbr % digit)];
			nbr = nbr / digit;
			idx--;
		}
		ans[idx] = '-';
	}
	else
	{
		while (0 <= idx)
		{
			ans[idx] = base[(nbr % digit)];
			nbr = nbr / digit;
			idx--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*ans;
	char	*base;
	int		size;

	base = "0123456789";
	size = malloc_size(n, ft_strlen(base));
	ans = (char *) malloc(sizeof(char) * size);
	if (ans == 0)
		return (0);
	ft_putnbr_base(n, base, ans);
	return (ans);
}
