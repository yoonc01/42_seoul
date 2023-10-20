/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:43:31 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/27 14:00:31 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	len;
	int	i;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	i = 0;
	while (i < len && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (!size)
		dest[i] = '\0';
	return (len);
}
