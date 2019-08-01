# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvromman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 15:22:35 by hvromman          #+#    #+#              #
#    Updated: 2018/10/04 15:22:46 by hvromman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = ./
OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
ft_isprint.o ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o \
ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o \
ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o \
ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o \
ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o \
ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ft_lstnew.o \
ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_indexof.o \
ft_strnjoin.o ft_min.o ft_max.o ft_tablen.o ft_free_tab.o

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEAD)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "$(RED)libft compiled$(NC)"

clean:
	@rm -f $(OBJ)
	@echo "$(GREEN)libft cleaned$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)libft fcleaned$(NC)"

re: fclean all
