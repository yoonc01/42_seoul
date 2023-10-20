/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:39:48 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/28 13:12:36 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		i;
	int		is_null;
	int		int_n;
	char	*ans;

	i = 0;
	is_null = 0;
	int_n = (int) n;
	ans = dest;
	while (i < int_n)
	{
		if (is_null)
			*dest = '\0';
		else
			*dest = *src;
		if (is_null == 0 && *src == '\0')
		{
			is_null = 1;
		}
		i++;
		dest++;
		src++;
	}
	return (ans);
}
