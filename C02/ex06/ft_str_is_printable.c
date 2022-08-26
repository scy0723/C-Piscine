/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:02:53 by chashin           #+#    #+#             */
/*   Updated: 2022/05/31 00:38:13 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	if (*str)
	{
		while (*str != '\0')
		{
			if (*str < 32 || *str == 127)
			{
				return (0);
			}
			str++;
		}
		return (1);
	}
	else
		return (1);
}
