/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:14:07 by chashin           #+#    #+#             */
/*   Updated: 2022/05/29 18:46:49 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		if ((*str >= 65 && *str <= 90))
			*str += 32;
		str++;
	}
	return (tmp);
}