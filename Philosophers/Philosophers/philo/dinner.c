/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:25:48 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/26 17:12:05 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleeping(long usec, t_table *table)
{
	long	rest;
	long	start;
	long	passed;

	start = get_time();
	while (get_time() - start < usec)
	{
		if (finished(table))
			break ;
		passed = get_time() - start;
		rest = usec - passed;
		if (rest > 2000)
			usleep(1000);
		else if (rest > 1000)
			usleep(500);
		else
		{
			while (get_time() - start < usec)
				;
		}
	}
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	display(TAKE_FORK, philo);
	if (philo->first_fork == philo->second_fork)
	{
		while (!finished(philo->table))
			;
		return ;
	}
	pthread_mutex_lock(philo->second_fork);
	display(TAKE_FORK, philo);
	display(EATING, philo);
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal_time = get_time();
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->philo_mutex);
	if (philo->eat_cnt == philo->table->must_eat)
		set_bool(&philo->philo_mutex, &philo->full, true);
	sleeping(philo->table->eat, philo->table);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

static void	for_fairness(t_philo *philo, int start)
{
	if (start)
	{
		if (philo->id % 2 == 1)
		{
			display(THINKING, philo);
			sleeping(philo->table->eat * 0.042, philo->table);
		}
	}
	else
	{
		if (philo->table->num % 2 == 1)
			sleeping(philo->table->think * 0.42, philo->table);
	}
}

void	*dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	philo->last_meal_time = get_time();
	safe_inc(&philo->table->table_mutex, &philo->table->count_th);
	for_fairness(philo, 1);
	while (!finished(philo->table))
	{
		if (philo->full)
			break ;
		if (!finished(philo->table))
			eating(philo);
		if (!finished(philo->table))
		{
			display(SLEEPING, philo);
			sleeping(philo->table->sleep, philo->table);
		}
		if (!finished(philo->table))
		{
			display(THINKING, philo);
			for_fairness(philo, 0);
		}
	}
	return (0);
}

int	dinner_start(t_table *table)
{
	int	idx;

	idx = 0;
	while (idx < table->num)
	{
		if (pthread_create(&table->philos[idx].th, 0,
				dinner, (void *) &table->philos[idx]) != 0)
			return (dinner_error(table, idx - 1, 0));
		idx++;
	}
	table->start_time = get_time();
	set_bool(&table->table_mutex, &table->ready, true);
	if (pthread_create(&table->monitor, 0, monitoring, (void *) table) != 0)
		return (dinner_error(table, idx - 1, 0));
	idx = 0;
	while (idx < table->num)
	{
		if (pthread_join(table->philos[idx].th, 0) != 0)
			return (dinner_error(table, idx + 1, 1));
		idx++;
	}
	if (pthread_join(table->monitor, 0) != 0)
		return (0);
	return (1);
}
