/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:48:36 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/03/28 19:33:11 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received_bit;

static void	sigusr1_handler(int sig)
{
	(void)sig;
	g_received_bit = 0;
}

static void	sigusr2_handler(int sig)
{
	(void)sig;
	g_received_bit = 1;
}

static void	receiver(void)
{
	int		i;
	char	c;

	while (1)
	{
		c = 0;
		i = 7;
		while (0 <= i)
		{
			pause();
			c = c + (g_received_bit << i);
			i--;
		}
		if (c == 0)
			break ;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

static void	positive(int n)
{
	char	d;

	if (0 <= n && n < 10)
	{
		d = n + '0';
		write(1, &d, 1);
		return ;
	}
	positive(n / 10);
	d = n % 10 + '0';
	write(1, &d, 1);
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;
	pid_t				pid;

	pid = getpid();
	positive(pid);
	write(1, "\n", 1);
	act1.sa_handler = sigusr1_handler;
	sigemptyset(&act1.sa_mask);
	act1.sa_flags = 0;
	sigaction(SIGUSR1, &act1, NULL);
	act2.sa_handler = sigusr2_handler;
	sigemptyset(&act2.sa_mask);
	act2.sa_flags = 0;
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
		receiver();
}
