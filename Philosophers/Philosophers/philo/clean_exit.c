/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:02:20 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/26 17:09:57 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_error(t_table *table, int idx, int table_mtx, int display_mtx)
{
	if (table_mtx)
		pthread_mutex_destroy(&table->table_mutex);
	if (display_mtx)
		pthread_mutex_destroy(&table->display_mutex);
	if (table->philos != 0)
		free(table->philos);
	if (table->forks != 0)
	{
		while (0 <= idx)
		{
			pthread_mutex_destroy(&table->forks[idx]);
			idx--;
		}
		free(table->forks);
	}
	return (0);
}

int	dinner_error(t_table *table, int idx, int type)
{
	if (type == 0)
	{
		while (0 <= idx)
		{
			pthread_join(table->philos[idx].th, 0);
			idx--;
		}
	}
	else
	{
		while (idx < table->num)
		{
			pthread_join(table->philos[idx].th, 0);
			idx++;
		}
		pthread_join(table->monitor, 0);
	}
	return (0);
}

void	clean_exit(t_table *table)
{
	int	idx;

	pthread_mutex_destroy(&table->display_mutex);
	pthread_mutex_destroy(&table->table_mutex);
	idx = 0;
	while (idx < table->num)
	{
		pthread_mutex_destroy(&table->forks[idx]);
		idx++;
	}
	free(table->forks);
	free(table->philos);
}
