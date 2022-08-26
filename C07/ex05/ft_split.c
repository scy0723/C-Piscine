/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:54:09 by chashin           #+#    #+#             */
/*   Updated: 2022/06/05 21:11:48 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	split_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	return (i);
}

int	wordcnt(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
		{
			cnt++;
			while (str[i] && !is_sep(str[i], charset))
				i++;
			continue ;
		}
		i++;
	}
	return (cnt);
}

void	cpy(char *src, char *dest, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		idx;
	char	**res;
	int		len;
	int		i;

	res = (char **)malloc(sizeof(char *) * wordcnt(str, charset) + 1);
	if (!res)
		return (0);
	idx = 0;
	i = 0;
	while (idx < wordcnt(str, charset) && str[i])
	{
		if (!is_sep(str[i], charset))
		{
			len = split_len(&str[i], charset);
			res[idx] = (char *)malloc(sizeof(char) * len + 1);
			cpy(&str[i], res[idx++], len);
			while (!is_sep(str[i], charset) && str[i])
				i++;
		}
		i++;
	}
	res[idx] = 0;
	return (res);
}
