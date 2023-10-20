/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:02:18 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/29 15:17:48 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	len1;
	unsigned int	len2;

	idx = 0;
	len1 = str_len(dest);
	len2 = str_len(src);
	if (size <= len1)
		return (size + len2);
	while (*src != '\0' && len1 < size - 1 && 0 < size)
	{
		dest[len1 + idx] = *src;
		idx++;
		src++;
	}
	dest[len1 + idx] = '\0';
	return (len1 + len2);
}
