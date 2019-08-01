# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvromman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 11:36:12 by hvromman          #+#    #+#              #
#    Updated: 2018/10/19 11:36:15 by hvromman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = ./
LIB = ./libft/
OBJ = main.o read.o verify.o backtracking.o exit.o

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEAD) -I $(LIB)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIB) -lft
	@echo "$(RED)fillit compiled$(NC)"

clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)
	@echo "$(GREEN)fillit cleaned$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB) fclean
	@echo "$(GREEN)fillit fcleaned$(NC)"

re: fclean all
