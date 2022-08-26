/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:26:59 by chashin           #+#    #+#             */
/*   Updated: 2022/06/07 21:45:07 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen3(char *str)
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

int	change_base(char *str, char *base, int sign, long long *g_i)
{
	while (*str)
	{
		if (find_in_base(*str, base) == -1)
		{
			str++;
			break ;
		}
		*g_i = *g_i * ft_strlen3(base) + find_in_base(*str, base);
		str++;
	}
	if (sign == -1)
		*g_i *= -1;
	return (0);
}

int	check_base(char *tmp)
{
	int		c[256];
	int		i;

	if (!*tmp || ft_strlen3(tmp) == 1)
		return (0);
	i = -1;
	while (i++ <= 256)
		c[i] = 0;
	while (*tmp)
	{
		if (*tmp == '\n' || *tmp == '\f' || *tmp == ' ' || *tmp == '\t'
			|| *tmp == '\r' || *tmp == '\v' || *tmp == '+' || *tmp == '-')
			return (0);
		if (c[(int)*tmp + 128] == 1)
			return (0);
		c[(int)*tmp + 128] = 1;
		tmp++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	char			*tmp;
	long long		g_i;
	int				sign;

	g_i = 0;
	sign = 1;
	tmp = base;
	while (*str == '\n' || *str == '\f' || *str == ' '
		|| *str == '\t' || *str == '\r' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	change_base(str, base, sign, &g_i);
	return (g_i);
}
