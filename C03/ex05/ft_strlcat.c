/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:52:24 by chashin           #+#    #+#             */
/*   Updated: 2022/06/09 19:50:48 by chashin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	_src;
	unsigned int	_dest;
	unsigned int	i;

	i = 0;
	_dest = ft_strlen(dest);
	_src = ft_strlen(src);
	if (size <= _dest)
		_src += size;
	else
		_src += _dest;
	while (src[i] && _dest + 1 < size)
	{
		dest[_dest++] = src[i++];
	}
	dest[_dest] = '\0';
	return (_src);
}
