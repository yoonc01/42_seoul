/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:44:28 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/15 23:08:24 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*create_deque(void)
{
	t_deque	*dq;

	dq = (t_deque *)malloc(sizeof(t_deque));
	if (dq == 0)
		exit(EXIT_FAILURE);
	dq->front = 0;
	dq->rear = 0;
	return (dq);
}

void	insert_front(t_deque *dq, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		exit(EXIT_FAILURE);
	new->data = data;
	new->next = dq->front;
	new->prev = 0;
	if (dq->front == 0)
		dq->rear = new;
	else
		dq->front->prev = new;
	dq->front = new;
}

void	insert_rear(t_deque *dq, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		exit(EXIT_FAILURE);
	new->data = data;
	new->next = 0;
	new->prev = dq->rear;
	if (dq->rear == 0)
		dq->front = new;
	else
		dq->rear->next = new;
	dq->rear = new;
}

void	delete_front(t_deque *dq)
{
	t_node	*temp;

	if (dq->front == 0)
		return ;
	temp = dq->front;
	dq->front = dq->front->next;
	if (dq->front == 0)
		dq->rear = 0;
	else
		dq->front->prev = 0;
	free(temp);
}

void	delete_rear(t_deque *dq)
{
	t_node	*temp;

	if (dq->rear == 0)
		return ;
	temp = dq->rear;
	dq->rear = dq->rear->prev;
	if (dq->rear == 0)
		dq->front = 0;
	else
		dq->rear->next = 0;
	free(temp);
}
