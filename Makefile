# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:39:13 by vlenard           #+#    #+#              #
#    Updated: 2022/11/29 19:14:58 by vlenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = get_next_line.c get_next_line_utils.c
OBJS = $(SRC:.c=.o)
NAME = gnl.a
N = 4

all: $(NAME) 
$(NAME) : $(OBJS) 
		ar rcs $(NAME) $(OBJS) 
c: all
		$(CC)  $(NAME) -D BUFFER_SIZE=$(N) main.c && ./a.out
n:
		norminette $(SRC)
clean :
		rm -f $(OBJS)
fclean : clean
		rm -f $(NAME)
re : fclean
		$(MAKE) all
.PHONY: all, m, b, n, clean, fclean, re