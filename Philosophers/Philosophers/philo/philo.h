/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:24 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/26 15:22:18 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mtx;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FORK,
	DEAD
}	t_status;

typedef struct s_philo
{
	int			id;
	long		eat_cnt;
	bool		full;
	long		last_meal_time;
	t_mtx		*first_fork;
	t_mtx		*second_fork;
	t_mtx		philo_mutex;
	pthread_t	th;
	t_table		*table;
}	t_philo;

struct s_table
{
	long		num;
	long		die;
	long		eat;
	long		sleep;
	long		think;
	long		must_eat;
	long		start_time;
	bool		end;
	bool		ready;
	long		count_th;
	pthread_t	monitor;
	t_mtx		table_mutex;
	t_mtx		display_mutex;
	t_mtx		*forks;
	t_philo		*philos;
};

long	my_atol(const char *str);
int		table_init(t_table *table);
bool	finished(t_table *table);
void	set_bool(t_mtx *mutex, bool *dst, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
bool	finished(t_table *table);
void	wait_all_threads(t_table *table);
long	get_time(void);
void	display(t_status status, t_philo *philo);
void	*dinner(void *data);
void	*monitoring(void *data);
int		dinner_start(t_table *table);
int		init_error(t_table *table, int idx, int table_mtx, int display_mtx);
int		dinner_error(t_table *table, int idx, int type);
void	before_end(t_table *table);
void	safe_inc(t_mtx *mutex, long *value);
void	clean_exit(t_table *table);

#endif
