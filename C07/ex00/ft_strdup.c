/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:00:04 by chashin           #+#    #+#             */
/*   Updated: 2022/06/06 13:43:35 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*new;
	char	*tmp;

	len = ft_strlen(src);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (0);
	tmp = new;
	while (*src)
	{
		*new = *src;
		new++;
		src++;
	}
	*new = '\0';
	return (tmp);
}
