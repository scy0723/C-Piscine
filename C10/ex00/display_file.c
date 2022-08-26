/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:24:22 by chashin           #+#    #+#             */
/*   Updated: 2022/06/08 16:22:05 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>

void display_file(char *fname)
{
	int fd;
	char b[100];
	int b_len;
	
	fd = open(fname, O_RDONLY);
	b_len = 1;
	while(b_len > 0)
	{
		b_len = read(fd, b, 100);
		write(1, b, b_len);
	}
	close(fd);
}