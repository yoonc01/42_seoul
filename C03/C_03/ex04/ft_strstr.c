/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:43:40 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/31 14:36:38 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	exist;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		exist = 1;
		while (to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j])
			{
				exist = 0;
				break ;
			}
			j++;
		}
		if (exist)
			return (&str[i]);
		i++;
	}
	return (0);
}

