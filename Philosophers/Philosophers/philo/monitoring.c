/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:05:44 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/25 18:33:16 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	all_ths_running(t_mtx *mutex, long *threads, long num)
{
	bool	for_return;

	for_return = false;
	pthread_mutex_lock(mutex);
	if (*threads == num)
		for_return = true;
	pthread_mutex_unlock(mutex);
	return (for_return);
}

static bool	check_dead(t_philo *philo)
{
	long	passed;
	long	die;
	long	t;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	pthread_mutex_lock(&philo->philo_mutex);
	t = philo->last_meal_time;
	pthread_mutex_unlock(&philo->philo_mutex);
	passed = get_time() - t;
	die = philo->table->die;
	if (passed > die)
		return (true);
	return (false);
}

static void	check_all_dead(t_table *table)
{
	int		idx;
	t_philo	*philo;

	idx = 0;
	while (idx < table->num)
	{
		philo = table->philos + idx;
		if (check_dead(philo))
		{
			set_bool(&table->table_mutex, &table->end, true);
			display(DEAD, table->philos + idx);
			return ;
		}
		idx++;
	}
}

static void	check_all_eat(t_table *table)
{
	int		idx;
	bool	all_eat;
	t_philo	*philo;

	idx = 0;
	all_eat = true;
	while (idx < table->num)
	{
		philo = table->philos + idx;
		if (!get_bool(&philo->philo_mutex, &philo->full))
			return ;
		idx++;
	}
	if (all_eat)
		set_bool(&table->table_mutex, &table->end, true);
}

void	*monitoring(void *data)
{
	t_table	*table;

	table = (t_table *) data;
	while (!all_ths_running(&table->table_mutex, &table->count_th, table->num))
		;
	while (!finished(table))
	{
		check_all_dead(table);
		check_all_eat(table);
	}
	return (0);
}
