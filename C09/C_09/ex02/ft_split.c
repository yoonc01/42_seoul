/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:21:48 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/07 21:14:27 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	strsame(char *str, char *charset)
{
	while (*str == *charset)
	{
		if (*charset == '\0')
			return (1);
		str++;
		charset++;
	}
	return (0);
}

void	to_null(char *str, int	len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	s_len;
	int	c_len;
	int	is_word;
	int	cnt;

	i = 0;
	s_len = ft_strlen(str);
	c_len = ft_strlen(charset);
	is_word = 0;
	cnt = 0;
	while (i < s_len)
	{
		if (strsame(str + i, charset))
		{
			to_null(str + i, c_len);
			is_word = 0;
		}
		else if(is_word == 0)
		{
			cnt++;
			is_word = 1;
		}
		i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		idx;
	int		is_word;
	int		len;
	char	**word_list

	i = 0;
	idx = 0;
	is_word = 0;
	word_list = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	while (i < ft_strlen(str))
	{
		if (str[i] != '\0' && is_word == 0)
		{
			len = ft_strlen(str + i);
			word_list[idx] = (char *)malloc(sizeof(char) * (len + 1));

			is_word = 1;
		}
		else
			is_word = 0;
		i++;
	}
	*word_list = 0;
	return (ans);
}

int	main(int ac, char **av)
{

