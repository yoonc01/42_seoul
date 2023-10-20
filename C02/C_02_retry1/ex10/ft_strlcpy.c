/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:09:13 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/27 20:12:06 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	len;

	len = 0;
	while (src[len] != '\0' && len < size - 1)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	while (src[len] != '\0')
	{
		len++;
	}
	return (len);
}
