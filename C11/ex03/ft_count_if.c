/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:09:29 by chashin           #+#    #+#             */
/*   Updated: 2022/06/07 18:26:40 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (f(tab[i++]) != 0)
			cnt++;
	}
	return (cnt);
}
