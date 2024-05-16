/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:18:37 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/15 23:37:52 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	t_node	*front;
	t_node	*rear;
}	t_deque;

void	do_swap(t_deque *dq1, t_deque *dq2, int len, int bit);
t_deque	*create_deque(void);
void	insert_front(t_deque *dq, int data);
void	insert_rear(t_deque *dq, int data);
void	delete_front(t_deque *dq);
void	do_len_3(int *arr);
void	do_len_4(int *arr);
void	do_len_5(int *arr);
int		idx_when_sorted(int *arr, int value, int size);
void	do_low_swap(int *arr, int len);
void	do_push_swap(int *arr, int *sorted_arr, int len);
int		my_atoi(char *str);
int		*sorted(int *arr, int n);
char	**split(char *s);
char	*strjoin(char *s1, char *s2);
void	free_dq(t_deque *dq1, t_deque *dq2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
