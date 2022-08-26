/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:16:00 by chashin           #+#    #+#             */
/*   Updated: 2022/05/29 18:45:37 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		first;
	char	*tmp;

	tmp = str;
	first = 1;
	while (*str)
	{
		if ((first == 1 && *str >= 97 && *str <= 122))
			*str -= 32;
		else if ((first == 0 && *str >= 65 && *str <= 90))
			*str += 32;
		if (*str < 48 || (*str > 57 && *str < 65))
			first = 1;
		else if ((*str > 90 && *str < 97) || *str > 122)
			first = 1;
		else
			first = 0;
		str++;
	}
	return (tmp);
}
