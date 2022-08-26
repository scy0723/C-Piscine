/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:01:24 by chashin           #+#    #+#             */
/*   Updated: 2022/06/09 15:49:12 by chashin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	hexa_print(unsigned char c)
{
	if (c > 9)
		c = '0' + c + 97 - 58;
	else
		c = '0' + c;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;

	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			c = *str;
			hexa_print(c / 16);
			hexa_print(c % 16);
		}
		str++;
	}
}
