/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:53:15 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/28 13:27:28 by hyoyoon          ###   ########.fr       */
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

int	is_alphanumeric(char c)
{
	if (is_lower(c))
		return (1);
	else if (is_upper(c))
		return (1);
	else if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || !is_alphanumeric(str[i - 1])) && is_lower(str[i]))
			str[i] = str[i] - 32;
		if ((i != 0 && is_alphanumeric(str[i - 1])) && is_upper(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
