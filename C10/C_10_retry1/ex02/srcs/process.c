/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:26:25 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/14 15:20:39 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

char	*process_file(int fd)
{
	char	buff[1024];
	int		size;
	char	*content;

	content = (char *)malloc(sizeof(char) * 1);
	if (content == 0)
		return (0);
	content[0] = 0;
	size = 1;
	while (0 < size)
	{
		size = read(fd, buff, 1024);
		if (0 < size)
			content = ft_strncat(content, buff, 1024);
	}
	return (content);
}

void	ft_tail(int given_cnt, int fd)
{
	char	*content;
	int		content_len;

	content = process_file(fd);
	content_len = ft_strlen(content);
	if (given_cnt > content_len)
		given_cnt = content_len;
	print_reverse(content, given_cnt);
}
