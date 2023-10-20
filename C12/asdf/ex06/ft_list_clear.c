/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_list_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:42:53 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 20:47:32 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*next;

	next = begin_list;
	while (next != 0)
	{
		current = next;
		next = next->next;
		(*free_fct)(current->data);
		free(current);
	}
}
