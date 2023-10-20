/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:02:18 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/31 14:51:18 by hyoyoon          ###   ########.fr       */
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
	unsigned int	d_len;
	unsigned int	s_len;

	idx = 0;
	d_len = str_len(dest);
	s_len = str_len(src);
	if (size <= d_len)
		return (size + s_len);
	while (*src != '\0' && d_len < size - 1 && 0 < size)
	{
		dest[d_len + idx] = *src;
		idx++;
		src++;
		size--;
	}
	dest[d_len + idx] = '\0';
	return (d_len + s_len);
}
