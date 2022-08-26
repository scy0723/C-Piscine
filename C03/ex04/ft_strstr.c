/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:55:34 by chashin           #+#    #+#             */
/*   Updated: 2022/05/30 16:04:55 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{	
	char	*_str;
	char	*_to_find;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			_str = str;
			_to_find = to_find;
			while (*_to_find)
			{
				_str++;
				_to_find++;
				if (*_to_find == '\0')
					return (str);
				else if (*_to_find != *_str)
					break ;
			}
		}
		str++;
	}
	return (0);
}
