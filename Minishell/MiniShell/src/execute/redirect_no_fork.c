/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_no_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:24:51 by ycho2             #+#    #+#             */
/*   Updated: 2024/10/03 09:43:29 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_redir_no_fork(t_inner_block_list *redir_list)
{
	int				flag;
	t_child_util	child_util;

	flag = 0;
	child_util.pipe_i = 0;
	child_util.pipecnt = 0;
	child_util.childfd[0] = STDIN_FILENO;
	child_util.childfd[1] = STDOUT_FILENO;
	if (set_cur_block_redir(redir_list, &child_util))
		return (1);
	dup2(child_util.childfd[0], STDIN_FILENO);
	dup2(child_util.childfd[1], STDOUT_FILENO);
	return (0);
}
