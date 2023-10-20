/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:31:17 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 20:39:08 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*ans;
	t_list	*next;
	int		i;

	i = 0;
	ans = ft_create_elem(strs[i]);
	next = ans;
	i++;
	while (i < size)
	{
		next->next = ft_create_elem(strs[i]);
		i++;
		next = next->next;
	}
	return (ans);
}
