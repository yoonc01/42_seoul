/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:24:51 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/10 13:24:39 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	plus(int a, int b);
void	minus(int a, int b);
void	div(int a, int b);
void	mul(int a, int b);
void	mod(int a, int b);

#endif
