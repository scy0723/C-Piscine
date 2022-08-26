/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:00:23 by chashin           #+#    #+#             */
/*   Updated: 2022/05/30 23:52:54 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	if (*str)
	{
		while (*str != '\0')
		{
			if ((*str >= 97 && *str <= 122))
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
