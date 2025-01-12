# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 23:24:57 by raica-ba          #+#    #+#              #
#    Updated: 2025/01/12 23:38:25 by raica-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

INCLUDES = .

FLAGS = -Wall -Wextra -Werror

SRC = conversion_functions.c unsigned_functions.c ft_printf.c utility_functions.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)
%.o: %.c
				$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@
clean:
				rm -rf $(OBJ)
fclean: clean
				rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
