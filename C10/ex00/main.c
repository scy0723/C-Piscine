/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:26:04 by chashin           #+#    #+#             */
/*   Updated: 2022/06/08 16:22:36 by chashin          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>

void display_file(char *fname);
int main(int argc, char **argv)
{
    int file;
    
    if (argc == 1)
        write(2, "File name missing.", 18);
    else if (argc > 2)
        write(2, "Too mamy arguments.", 19);
    else{
        file = open(argv[1], O_RDONLY);
        if (file == 0)
            write(2, "Cannot read file.", 17);
        else{
            close(file);
            display_file(argv[1]);
        }
    }
}