/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:29:41 by chashin           #+#    #+#             */
/*   Updated: 2022/06/07 23:12:48 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort1(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i++ < length - 1)
	{
		if (f(*tab, *(tab + 1)) > 0)
			return (0);
		tab++;
	}
	return (1);
}

int	ft_is_sort2(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i++ < length - 1)
	{
		if (f(*tab, *(tab + 1)) < 0)
			return (0);
		tab++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	*tmp;

	tmp = tab;
	return (ft_is_sort1(tab, length, f) || ft_is_sort2(tmp, length, f));
}
