/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:42:18 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/25 22:42:51 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	while ((*src) != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (dest);
}
