/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:33:07 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/12 15:35:34 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src, int size);
void	print_last(char **set, int cnt);
void	add_str(char **set, char *str);

void	init_set(char **set);
void	free_set(char **set);
int		max_ten(int n);

#endif
