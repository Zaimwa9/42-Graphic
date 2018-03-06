# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzaim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:26:15 by wzaim             #+#    #+#              #
#    Updated: 2017/12/25 18:18:23 by wzaim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./
SRC_NAMES = ft_exit.c \
			get_next_line.c \
			ft_toupper.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isascii.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_strcmp.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strclr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_memset.c \
			ft_strcat.c \
			ft_strdup.c \
			ft_strncat.c \
			ft_strncpy.c \
			ft_strncmp.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_bzero.c \
			ft_strlcat.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memset.c \
			ft_memccpy.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_atoi.c \
			ft_strnew.c \
			ft_strsub.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strdel.c \
			ft_striter.c \
			ft_striteri.c \
			ft_striteri.c \
			ft_strsplit.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_itoa.c \
			ft_memcpy.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_is_prime.c \
			ft_sqrt.c \
			ft_power.c \
			ft_is_include.c \
			ft_strcpy.c

SRC = $(addprefix $(SRC_DIR), $(SRC_NAMES))

OBJ_DIR = ./
OBJ_NAMES = $(SRC_NAMES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAMES))

INC_DIR = ./includes/
INC = $(addprefix -I, $(INC_DIR))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Preparing libft !"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libft ready !"

%.o: %.c
	@$(CC) -o $@ -c $< $(INC) $(CFLAGS)

fclean: clean
	@rm -f $(NAME)
	@echo "libft COMPLETELY cleaned boss !"

clean:
	@rm -f $(OBJ)

re: fclean all
	@echo "Encore du travail ? Treees bien"
