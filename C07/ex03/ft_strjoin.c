/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:26:10 by chashin           #+#    #+#             */
/*   Updated: 2022/06/06 14:15:44 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

char	*sepcat(char *dest, char *sep, char *src)
{
	dest = ft_strcat(dest, sep);
	dest = ft_strcat(dest, src);
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		total;
	char	*tmp;

	if (size == 0)
	{
		res = (char *)malloc(1);
		*res = 0;
		return (res);
	}
	i = 0;
	total = 0;
	while (i < size)
		total += ft_strlen2(strs[i++]);
	total += (size - 1) * ft_strlen2(sep) + 1;
	res = (char *)malloc(sizeof(char) * total);
	if (!res)
		return (0);
	i = 0;
	tmp = ft_strcat(res, strs[i++]);
	while (i < size)
		tmp = sepcat(tmp, sep, strs[i++]);
	return (res);
}
