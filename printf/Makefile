# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 12:29:49 by aaskal            #+#    #+#              #
#    Updated: 2024/05/12 16:46:13 by aaskal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
SRCS = ft_isdigit.c ft_numlen.c ft_numlen_hex.c ft_printchar.c ft_printf.c ft_printint.c ft_printstr.c ft_printuint.c ft_printx.c ft_strlen.c handle_hash_flag.c handle_plus_flag.c  handle_space_flag.c  print_spaces.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@
 
 bonus: all
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	

.PHONY: all clean fclean re