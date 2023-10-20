/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:07:22 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/15 19:47:32 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;
	void	*temp;

	newlst = 0;
	while (lst != 0)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (new == 0)
		{
			(*del)(temp);
			if (newlst != 0)
				ft_lstclear(&newlst, del);
			free(newlst);
			return (0);
		}
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	return (newlst);
}
