/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:53:15 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/27 20:03:23 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	is_upper(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || str[i - 1] == ' ') && is_lower(str[i]))
			str[i] = str[i] - 32;
		if ((i != 0 && str[i - 1] != ' ') && is_upper(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
