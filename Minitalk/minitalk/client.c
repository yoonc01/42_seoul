/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:48:28 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/03/28 19:24:44 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(pid_t pid, int bit)
{
	int	signal;

	signal = SIGUSR1 + bit;
	if (kill(pid, signal) == -1)
		write(1, "fail to send the signal\n", 24);
}

static void	send_char(pid_t pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (0 <= i)
	{
		bit = (c >> i) & 1;
		send_bit(pid, bit);
		usleep(100);
		i--;
	}
}

static int	all_digit(char *str)
{
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*message;
	pid_t	pid;

	if (ac != 3)
	{
		write(2, "Form has to be 'client' 'pid' 'string'\n", 39);
		return (1);
	}
	if (!all_digit(av[1]))
	{
		write(2, "PID has to be an int\n", 21);
		return (1);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	while (*message != '\0')
	{
		send_char(pid, *message);
		message++;
	}
	return (0);
}
