/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:01:55 by chashin           #+#    #+#             */
/*   Updated: 2022/05/30 23:53:00 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	if (*str)
	{
		while (*str != '\0')
		{
			if ((*str >= 65 && *str <= 90))
			{
				str++;
				continue ;
			}
			else
				return (0);
			str++;
		}
		return (1);
	}
	else
		return (1);
}
