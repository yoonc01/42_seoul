/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:20:40 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/09 20:55:32 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	not_valid(char *base);
int	base_to_num(char *base, char c);
int	in_base(char *base, char c);

int	malloc_size(int nbr, int digit)
{
	int	size;

	size = 0;
	if (nbr < 0)
		size++;
	else if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / digit;
		size++;
	}
	return (size);
}

void	ft_putnbr_base(int nbr, char *base, char *ans)
{
	int		digit;
	int		idx;

	digit = ft_strlen(base);
	idx = malloc_size(nbr, digit) - 1;
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

int	ft_atoi_base(char *str, char *base)
{
	int	ans;
	int	minus;
	int	digit;

	ans = 0;
	minus = 0;
	digit = ft_strlen(base);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = !minus;
		str++;
	}
	while (in_base(base, *str))
	{
		ans = ans * digit + base_to_num(base, *str);
		str++;
	}
	if (minus)
		ans = -1 * ans;
	return (ans);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*ans;
	int		size;

	if (not_valid(base_from) || not_valid(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	size = malloc_size(num, ft_strlen(base_to));
	ans = (char *)malloc(sizeof(char) * (size));
	ft_putnbr_base(num, base_to, ans);
	return (ans);
}
