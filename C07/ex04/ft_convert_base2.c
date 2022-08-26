/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:58:04 by chashin           #+#    #+#             */
/*   Updated: 2022/06/07 21:45:25 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int		ft_strlen3(char *str);
int		check_base(char *tmp);
int		ft_atoi_base(char *str, char *base);
int		find_in_base(char c, char *base);
int		change_base(char *str, char *base, int sign, long long *g_i);

void	change_base2(long long nbr, char *base, char **gres, int *gindex)
{
	long long	i;

	if (nbr == 0)
		return ;
	change_base2(nbr / ft_strlen3(base), base, gres, gindex);
	i = nbr % ft_strlen3(base);
	(*gres)[*gindex] = *(base + i);
	(*gindex)++;
}

void	if_minus(int *nbr, char *base, char **gres, int *gindex)
{
	long long	ui;

	ui = *nbr;
	(*gres)[*gindex] = '-';
	(*gindex)++;
	change_base2(ui * -1, base, gres, gindex);
}

void	ft_putnbr_base(int nbr, char *base, char **gres, int *gindex)
{
	if (nbr == 0)
		(*gres)[(*gindex)++] = *base;
	else if (nbr < 0)
		if_minus(&nbr, base, gres, gindex);
	else
		change_base2(nbr, base, gres, gindex);
	(*gres)[*gindex] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	char	*gres;
	int		gindex;

	gres = (char *)malloc(sizeof(char) * 10000);
	if (!gres)
		return (0);
	gindex = 0;
	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	else
	{
		i = ft_atoi_base(nbr, base_from);
		ft_putnbr_base(i, base_to, &gres, &gindex);
		return (gres);
	}
}
