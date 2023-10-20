/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:18:16 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 20:20:30 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*next;
	int		len;

	next = begin_list;
	len = 0;
	while (next != 0)
	{
		next = next->next;
		len++;
	}
	return (len);
}
