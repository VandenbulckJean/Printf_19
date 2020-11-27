# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 16:40:44 by jvanden-          #+#    #+#              #
#    Updated: 2020/11/27 14:45:57 by jvanden-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Werror -Wall -Wextra

NAME = libftprintf.a

SRC = printf.c \
	printf_utils.c \
	printf_utils_2.c \
	printf_flag_utils.c \
	printf_conversion_utils.c \
	conversion_d.c \
	conversion_c.c \
	conversion_s.c \
	conversion_p.c \
	conversion_uxX.c \
	conversion_percent.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) printf.h
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

