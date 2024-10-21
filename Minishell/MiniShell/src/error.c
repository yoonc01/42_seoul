/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <hyoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:22:43 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/09/07 16:04:41 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	malloc_fail(void)
{
	perror("Failed to allocate memory\n");
	exit(EXIT_FAILURE);
}

void	argc_err(void)
{
	perror("argc error\n");
	exit(EXIT_FAILURE);
}
