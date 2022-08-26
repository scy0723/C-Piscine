/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:05:35 by chashin           #+#    #+#             */
/*   Updated: 2022/05/31 00:21:16 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_num[10];

void	rec2(int first, int n, int now)
{
	int	i;
	int	*pntr;
	int	j;

	if (n == now)
	{
		pntr = g_num;
		j = 0;
		while (j++ < n)
		{
			write(1, pntr, 1);
			pntr++;
		}
		write(1, ", ", 2);
		return ;
	}
	if (first == 9)
		return ;
	i = first + 1;
	while (i <= 10 - n + now)
	{
		g_num[now] = i + '0';
		rec2(i, n, now + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	last_num;

	i = 0;
	while (i < 10 - n)
	{
		g_num[0] = i + '0';
		rec2(i, n, 1);
		i++;
	}
	if (i == 10 - n)
	{
		while (i < 10)
		{
			last_num = '0' + i;
			i++;
			write(1, &last_num, 1);
		}
	}
}
