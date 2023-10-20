/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:53 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/27 19:15:57 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	is_null;
	char	*ans;

	ans = dest;
	i = 0;
	is_null = 0;
	while (i < n)
	{
		if (is_null)
			*dest = '\0';
		else
			*dest = *src;
		if (*src == '\0')
		{
			is_null = 1;
			*(src++) = '\0';
		}
		i++;
		dest++;
		src++;
	}
	return (ans);
}

int main()
{
	char dest[] = "ajklf";
	char str[] = "This is a string";
	ft_strncpy(dest, str, 6);
	printf("%s", dest);
}

