/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:27:52 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/31 19:37:22 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	return (len);
}

int	not_valid(char *base)
{
	char	*current;
	char	*cmp;

	current = base;
	if (*current == '\0')
		return (1);
	while (*current == '\0')
	{
		if (*current == '+' || *current == '-')
			return (1);
		cmp = current + 1;
		while (*cmp != '\0')
		{
			if (*current == *cmp)
				return (1);
			cmp++;
		}
		current++;
	}
	return (0);
}

int	base_to_num(char *base, char c)
{
	int	num;

	num = 0;
	while (base[num] != c)
		num++;
	return (num);
}

int	in_base(char *base, char c)
{
	while (*base != '\0')
	{
		if (*base == c)
			return (1);
		base++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ans;
	int	minus;

	ans = 0;
	minus = 0;
	if (not_valid(base))
		return (0);
	while (!in_base(base, *str) && *str != '+' && *str != '-')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = !minus;
		str++;
	}
	while (in_base(base, *str))
	{
		ans = ans * str_len(base) + base_to_num(base, *str);
		str++;
	}
	if (minus)
		ans = -1 * ans;
	return (ans);
}
