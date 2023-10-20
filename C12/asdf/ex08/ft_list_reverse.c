/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:53:06 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 21:02:02 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*temp;

	current = begin_list[0];
	next = current->next;
	temp = 0;
	current->next = temp;	
	while (next != 0)
	{
		current = next;
		next = current->next;
		current->next = 

