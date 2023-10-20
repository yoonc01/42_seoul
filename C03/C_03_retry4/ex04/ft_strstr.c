/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:43:40 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/02 21:16:09 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	exist;

	while (*str != '\0' || *to_find == '\0')
	{
		i = 0;
		exist = 1;
		while (to_find[i] != '\0')
		{
			if (str[i] != to_find[i])
			{
				exist = 0;
				break ;
			}
			i++;
		}
		if (exist)
			return (str);
		str++;
	}
	return (0);
}
