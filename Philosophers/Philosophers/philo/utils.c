/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:28:24 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/25 18:02:59 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->ready))
		;
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	display(t_status status, t_philo *philo)
{
	long	current_time;

	current_time = get_time() - philo->table->start_time;
	current_time = current_time / 1000;
	pthread_mutex_lock(&philo->table->display_mutex);
	if (status == DEAD)
		printf("%-6ld %d died\n", current_time, philo->id);
	else if (!finished(philo->table))
	{
		if (status == TAKE_FORK)
			printf("%-6ld %d has taken a fork\n", current_time, philo->id);
		else if (status == EATING)
			printf("%-6ld %d is eating\n", current_time, philo->id);
		else if (status == SLEEPING)
			printf("%-6ld %d is sleeping\n", current_time, philo->id);
		else if (status == THINKING)
			printf("%-6ld %d is thinking\n", current_time, philo->id);
	}
	pthread_mutex_unlock(&philo->table->display_mutex);
}

bool	finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end));
}
