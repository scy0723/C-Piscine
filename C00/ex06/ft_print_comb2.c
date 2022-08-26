/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:14:18 by chashin           #+#    #+#             */
/*   Updated: 2022/05/31 00:29:47 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_num2(int num)
{
	char	tens;
	char	ones;

	tens = '0' + num / 10;
	ones = '0' + num % 10;
	write(1, &tens, 1);
	write(1, &ones, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			print_num2(i);
			write(1, " ", 1);
			print_num2(j);
			if (i < 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
