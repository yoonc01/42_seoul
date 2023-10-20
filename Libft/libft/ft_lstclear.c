/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:59:27 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/12 15:20:11 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while ((*lst) != 0)
	{
		next = (*lst)->next;
		ft_lstdelone((*lst), (*del));
		(*lst) = next;
	}
	*lst = 0;
}
