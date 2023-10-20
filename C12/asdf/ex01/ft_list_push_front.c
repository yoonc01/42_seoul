/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:08:26 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 20:17:36 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*front;

	front = ft_create_elem(data);
	if (front != 0)
	{
		if (begin_list[0] != 0)
			front->next = begin_list[0];
		begin_list[0] = front;
	}
}
