/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:39:42 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 19:54:08 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h" 

void	write_last_ten(void)
{
	char	**set;
	char	buff[512];
	char	*str;
	int		size;
	int		cnt;

	set = (char **)malloc(sizeof(char *) * 11);
	init_set(set);
	cnt = 0;
	while (1)
	{
		size = read(0, buff, 512);
		if (size == 0)
			break ;
		str = ft_strdup(buff, size);
		cnt = max_ten(cnt + 1);
		add_str(set, str);
	}
	print_last(set, cnt);
	free_set(set);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write_last_ten();
		return (0);
	}
	(void)av;
}
