# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 00:18:25 by aaskal            #+#    #+#              #
#    Updated: 2024/05/13 12:28:43 by aaskal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft.a
PRINTF = printf.a
LIBFT_DIR = ./libft
PRINTF_DIR = ./printf

BONUS_DIR = ./Bonus
MANDATORY_DIR = ./Mandatory

BONUS_NAME = checker
MANDATORY_NAME = push_swap

BONUS_SRC = $(wildcard $(BONUS_DIR)/*.c) $(BONUS_DIR)/getnextlien/get_next_line.c $(BONUS_DIR)/getnextlien/get_next_line_utils.c
MANDATORY_SRC = $(wildcard $(MANDATORY_DIR)/*.c)

BONUS_OBJ = $(BONUS_SRC:.c=.o)
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

all: $(LIBFT)   $(PRINTF) $(MANDATORY_NAME) 

$(MANDATORY_NAME): $(MANDATORY_OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_DIR)/$(LIBFT)  $(PRINTF_DIR)/$(PRINTF)

bonus: $(LIBFT)  $(PRINTF)  $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_DIR)/$(LIBFT)  $(PRINTF_DIR)/$(PRINTF)
	

%.o: %.c Mandatory/push_swap.h Bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make   -C $(LIBFT_DIR)

$(PRINTF):
	@make  -C $(PRINTF_DIR)

clean:
	@rm -f $(BONUS_OBJ) $(MANDATORY_OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(BONUS_NAME) $(MANDATORY_NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

42:  all bonus clean 

re: fclean all

.PHONY: all bonus clean fclean re