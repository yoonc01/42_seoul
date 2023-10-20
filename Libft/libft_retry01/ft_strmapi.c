/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:03:04 by yunhyojun         #+#    #+#             */
/*   Updated: 2023/10/15 15:27:35 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ans;
	unsigned int	idx;

	idx = 0;
	ans = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ans == 0)
		return (0);
	while (s[idx] != '\0')
	{
		ans[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	ans[idx] = '\0';
	return (ans);
}
