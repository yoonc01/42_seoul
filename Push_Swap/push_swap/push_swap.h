/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:18:37 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/16 18:00:49 by hyoyoon          ###   ########.fr       */
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
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(const char *s, char c);
int		my_atoi(char *str);
void	sort_arr(int *arr, int n);
int		*sorted(int *arr, int n);
t_deque	*relative_dq(int *arr, int *sorted_arr, int n);
t_deque	*create_deque(void);
void	insert_front(t_deque *dq, int data);
void	insert_rear(t_deque *dq, int data);
void	delete_front(t_deque *dq);
void	delete_rear(t_deque *dq);
void	free_dq(t_deque *dq1, t_deque *dq2);
void	free_split(char **split);
void	free_arr(int *arr, int *sorted_arr);
void	do_push_swap(int *arr, int *sorted_arr, int len);

#endif
