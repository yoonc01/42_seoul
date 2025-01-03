/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:42:26 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/26 16:43:13 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (('A' <= *str && *str <= 'Z') || ('a' <= *str && *str <= 'z'))
			;
		else
			return (0);
		str++;
	}
	return (1);
}
