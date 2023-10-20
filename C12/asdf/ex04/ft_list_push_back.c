/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_list_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:25:08 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 20:39:49 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*next;
	t_list	*last;

	next = begin_list[0];
	last = ft_create_elem(data);
	while (next != 0)
	{
		if (next->next == 0)
			break ;
		next = next->next;
	}
	next->next = last;
}
