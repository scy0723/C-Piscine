/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:42:59 by chashin           #+#    #+#             */
/*   Updated: 2022/05/31 00:02:59 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	if (*str)
	{
		while (*str)
		{
			if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
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
