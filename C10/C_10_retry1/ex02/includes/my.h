/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:37:13 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/14 15:18:15 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
#define MY_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>

typedef struct s_cmd{
	int	len;
	int	idx;
	int	read;
}	t_cmd;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	print_reverse(char *str, int given);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strncat(char *old, char *add, int n);
void	ft_tail(int given_cnt, int fd);

#endif
