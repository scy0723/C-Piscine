/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <scy0723123@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:47:11 by chashin           #+#    #+#             */
/*   Updated: 2022/06/09 15:47:33 by chashin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_body(unsigned char *str, int size, int i);

void	print_hexnum(unsigned long long addr, int size)
{
	unsigned long long	div;

	div = addr / 16;
	if (size > 1)
		print_hexnum(div, size - 1);
	write(1, &"0123456789abcdef"[addr % 16], 1);
}

void	print_hexstr(unsigned long str)
{
	write(1, &"0123456789abcdef"[str / 16], 1);
	write(1, &"0123456789abcdef"[str % 16], 1);
}

void	print_char(char str)
{
	if (!((32 <= str && str <= 126)))
		write(1, ".", 1);
	else
		write(1, &str, 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int					i;
	unsigned char		*str;
	int					iter_size;

	str = (unsigned char *)addr;
	if ((size % 16) != 0)
		iter_size = ((size / 16) * 16) + 16;
	else
		iter_size = size;
	i = 0;
	while (i < iter_size)
	{
		print_body(str, size, i);
		i++;
	}
	return (addr);
}

void	print_body(unsigned char *str, int size, int i)
{
	unsigned long long	addrn;
	int					j;

	if ((i % 16) == 0)
	{
		addrn = (unsigned long long)&str[i];
		print_hexnum(addrn, 16);
		write(1, ":", 1);
	}
	if (i % 2 == 0)
		write(1, " ", 1);
	if (i < size)
		print_hexstr(str[i]);
	else
		write(1, "  ", 2);
	if ((i % 16 == 15))
	{
		j = i - 15;
		write(1, " ", 1);
		while (j <= i && j < size)
			print_char(str[j++]);
		write(1, "\n", 1);
	}
}
