/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:13:03 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/26 18:17:43 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mtx *mutex, bool *dst, bool value)
{
	pthread_mutex_lock(mutex);
	*dst = value;
	pthread_mutex_unlock(mutex);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	for_return;

	pthread_mutex_lock(mutex);
	for_return = *value;
	pthread_mutex_unlock(mutex);
	return (for_return);
}

void	safe_inc(t_mtx *mutex, long *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}
