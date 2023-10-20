/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:09:13 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/29 14:40:32 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (src[len] != '\0' && len < size - 1 && 0 < size)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	while (src[len] != '\0')
		len++;
	return (len);
}
