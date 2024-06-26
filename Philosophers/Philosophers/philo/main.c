/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:22:55 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/26 15:22:00 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parsing(int ac, char **av, t_table *table)
{
	if (ac != 5 && ac != 6)
		return (0);
	table->num = my_atol(av[1]);
	table->die = my_atol(av[2]) * 1000;
	table->eat = my_atol(av[3]) * 1000;
	table->sleep = my_atol(av[4]) * 1000;
	table->must_eat = -1;
	if (table->num <= 0 || table->die < 0 || table->eat < 0 || table->sleep < 0)
		return (0);
	table->think = 2 * table->eat - table->sleep;
	if (table->think < 0)
		table->think = 0;
	if (ac == 6)
	{
		table->must_eat = my_atol(av[5]);
		if (table->must_eat < 0)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (parsing(ac, av, &table) == 0)
		return (1);
	if (table.must_eat == 0)
		return (0);
	if (table_init(&table) == 0)
		return (1);
	if (dinner_start(&table) == 0)
	{
		init_error(&table, table.num, 1, 1);
		return (1);
	}
	clean_exit(&table);
	return (0);
}
