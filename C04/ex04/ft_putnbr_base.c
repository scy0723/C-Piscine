/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:13:28 by chashin           #+#    #+#             */
/*   Updated: 2022/06/01 19:34:33 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen1(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	change_base(unsigned int nbr, char *base)
{
	unsigned int	i;

	if (nbr == 0)
		return ;
	change_base(nbr / ft_strlen1(base), base);
	i = nbr % ft_strlen1(base);
	write(1, base + i, 1);
}

void	if_minus(int *nbr, char *base)
{
	unsigned int	ui;

	write(1, "-", 1);
	if (*nbr == -2147483648)
	{
		ui = 2147483648;
		change_base(ui, base);
	}
	else
		change_base(*nbr * -1, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				c[127];
	int				i;
	char			*tmp;

	tmp = base;
	if (!*tmp || ft_strlen1(tmp) == 1)
		return ;
	i = -1;
	while (i++ <= 127)
		c[i] = 0;
	while (*tmp)
	{
		if (*tmp == '+' || *tmp == '-')
			return ;
		if (c[(int)*tmp] == 1)
			return ;
		c[(int)*tmp] = 1;
		tmp++;
	}
	if (nbr == 0)
		write(1, "0", 1);
	else if (nbr < 0)
		if_minus(&nbr, base);
	else
		change_base(nbr, base);
}
