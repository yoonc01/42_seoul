/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:17:31 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/07 13:20:23 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	not_valid(char *base)
{
	char	*current;
	char	*cmp;

	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	current = base;
	while (*current != '\0')
	{
		if (*current == '+' || *current == '-')
			return (1);
		if ((9 <= *current && *current <= 13) || *current == 32)
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
