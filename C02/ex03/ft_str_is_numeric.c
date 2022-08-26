/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:56:02 by chashin           #+#    #+#             */
/*   Updated: 2022/05/30 23:52:41 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	if (*str)
	{
		while (*str != '\0')
		{
			if ((*str >= 48 && *str <= 57))
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
