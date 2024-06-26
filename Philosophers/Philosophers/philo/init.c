/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:27:04 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/26 17:13:25 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_mtx *forks, int position)
{
	int	num;

	num = philo->table->num;
	if (philo->id % 2 == 1)
	{
		philo->first_fork = &forks[(position + 1) % num];
		philo->second_fork = &forks[position];
	}
	else
	{
		philo->first_fork = &forks[position];
		philo->second_fork = &forks[(position + 1) % num];
	}
}

static int	philo_init(t_table *table)
{
	int		idx;
	t_philo	*philo;

	idx = 0;
	while (idx < table->num)
	{
		philo = table->philos + idx;
		philo->table = table;
		philo->id = idx + 1;
		philo->eat_cnt = 0;
		philo->full = false;
		assign_forks(philo, table->forks, idx);
		if (pthread_mutex_init(&philo->philo_mutex, 0) != 0)
		{
			while (0 <= --idx)
			{
				philo = table->philos + idx;
				pthread_mutex_destroy(&philo->philo_mutex);
			}
			return (0);
		}
		idx++;
	}
	return (1);
}

int	table_init(t_table *table)
{
	int	idx;

	table->end = false;
	table->ready = false;
	table->count_th = 0;
	if (pthread_mutex_init(&table->table_mutex, 0) != 0)
		return (0);
	if (pthread_mutex_init(&table->display_mutex, 0) != 0)
		return (init_error(table, -1, 1, 0));
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->num);
	if (table->philos == 0)
		return (init_error(table, -1, 1, 1));
	table->forks = (t_mtx *)malloc(sizeof(t_mtx) * table->num);
	if (table->forks == 0)
		return (init_error(table, -1, 1, 1));
	idx = 0;
	while (idx < table->num)
	{
		if (pthread_mutex_init(&table->forks[idx], 0) != 0)
			return (init_error(table, idx - 1, 1, 1));
		idx++;
	}
	if (philo_init(table) == 0)
		return (init_error(table, idx - 1, 1, 1));
	return (1);
}
