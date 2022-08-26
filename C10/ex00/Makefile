# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 15:43:44 by chashin           #+#    #+#              #
#    Updated: 2022/06/08 16:24:10 by chashin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_display_file
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
		
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
