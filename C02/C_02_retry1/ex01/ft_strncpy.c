/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:39:48 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/28 13:09:40 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		i;
	int		is_null;
	char	*ans;

	i = 0;
	is_null = 0;
	ans = dest;
	while (i < n)
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

#include <stdio.h>

int main()
{
	char arr1[] = "asd";
	char arr2[] = "ajkdf";

	ft_strncpy(arr1, arr2, 2);
	printf("%s", arr1);
}
