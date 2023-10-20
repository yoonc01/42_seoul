/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:26:10 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/04 19:37:37 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	uc;

	str = (unsigned char *) b;
	uc = (unsigned char) c;
	while (0 < len)
	{
		*str = uc;
		str++;
		len--;
	}
	return (b);
}
