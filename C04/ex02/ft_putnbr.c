/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:22:00 by chashin           #+#    #+#             */
/*   Updated: 2022/06/01 16:56:45 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec(int nb)
{
	int	i;

	if (nb == 0)
		return ;
	rec(nb / 10);
	i = '0' + nb % 10;
	write(1, &i, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			rec(214748364);
			write(1, "8", 1);
			return ;
		}
		nb *= -1;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	rec(nb);
}
