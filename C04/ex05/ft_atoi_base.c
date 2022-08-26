/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:35:34 by chashin           #+#    #+#             */
/*   Updated: 2022/06/01 20:06:52 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned int	g_i;

int	ft_strlen2(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		else
			i++;
	}
	return (-1);
}

void	change_base2(char *str, char *base, int sign)
{
	while (*str)
	{
		if (find_in_base(*str, base) == -1)
			break ;
		g_i = g_i * ft_strlen2(base) + find_in_base(*str, base);
		str++;
	}
	if (sign == -1)
		g_i *= -1;
}

int	check_base(int *c, char *tmp)
{
	while (*tmp)
	{
		if (*tmp == '+' || *tmp == '-' || *tmp <= 32 || *tmp == 127)
			return (0);
		if (c[(int)*tmp] == 1)
			return (0);
		c[(int)*tmp] = 1;
		tmp++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		c[127];
	int		i;
	char	*tmp;

	g_i = 0;
	tmp = base;
	if (!*tmp || ft_strlen2(tmp) == 1)
		return (0);
	i = -1;
	while (i++ <= 127)
		c[i] = 0;
	if (check_base(c, tmp) == 0)
		return (0);
	if (*str == '-')
	{
		str++;
		change_base2(str, base, -1);
	}
	else
		change_base2(str, base, 1);
	return (g_i);
}
