/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memorry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:22:27 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/30 22:40:38 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long long addr)
{
	char	last_digit;

	if (addr == 0)
		return ;
	last_digit = (addr % 16);
	print_addr(addr / 16);
	write(1, &"0123456789abcdef"[last_digit], 1);
}

void	print_hexa(void *addr, unsigned int size)
{
	unsigned int	n;
	unsigned char	*ptr;

	n = 0;
	ptr = addr;
	while (n < 16 && 0 < size)
	{
		write(1, &"0123456789abcdef"[(*ptr) / 16], 1);
		write(1, &"0123456789abcdef"[(*ptr) % 16], 1);
		if (n % 2)
			write(1, " ", 1);
		n++;
		ptr++;
		size--;
	}
	while (n < 16)
	{
		write(1, "  ", 2);
		if (n % 2)
			write(1, " ", 1);
		n++;
	}
}

void	print_string(void *addr, unsigned int size)
{
	unsigned int	n;
	unsigned char	*ptr;

	n = 0;
	ptr = addr;
	while (n < 16 && 0 < size)
	{
		if (' ' <= *ptr && *ptr <= '~')
			write(1, ptr, 1);
		else
			write(1, ".", 1);
		n++;
		ptr++;
		size--;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned char	*ans;

	ptr = addr;
	ans = addr;
	print_addr((unsigned long long) ptr);
	write(1, ": ", 2);
	print_hexa(ptr, size);
	print_string(ptr, size);
	if (16 < size)
	{
		ft_print_memory(ptr + 16, size - 16);
	}
	return (ans);
}
