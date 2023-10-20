/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:06:13 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/13 23:27:41 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
# define MY_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int		lines;
	int		length;
	char	empty;
	char	fill;
	char	obs;
	int		**map;
}	t_map;

typedef struct s_point
{
	int	r;
	int	c;
}	t_point;

char	*strncat_malloc(char *old, char *add, int n);
int		get_line_length(char *str);
int		get_map_size(char *file);
t_map	*mapping(char *file);
int		first_line(char *str_map, t_map *map);
int		map_ok(char *str_map, t_map *map);
char	*process_file(int fd, int filesize);
void	solve(t_map *map, int max);
int		**split(char *str, char *charset, t_map *map);
void	do_stdin(void);
int		**str_to_matrix(char *str, t_map *map);
int		ft_strlen(char *str);
int		ft_atoi(char *str, int n);
void	ft_putchar(char c);

#endif
