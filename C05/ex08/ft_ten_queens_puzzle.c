/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:07:32 by chashin           #+#    #+#             */
/*   Updated: 2022/06/02 17:47:02 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	g_nq[10];
int	g_cnt;

int	_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	check_constrains(int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (g_nq[i] == g_nq[index])
			return (0);
		if (_abs(g_nq[i] - g_nq[index]) == _abs(i - index))
			return (0);
		i++;
	}
	return (1);
}

void	print_nq(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = g_nq[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	nqueen(int index)
{
	int	i;

	i = 0;
	if (index > 9)
	{
		print_nq();
		g_cnt++;
		return ;
	}	
	while (i < 10)
	{
		g_nq[index] = i;
		if (check_constrains(index))
			nqueen(index + 1);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	g_cnt = 0;
	nqueen(0);
	return (g_cnt);
}
