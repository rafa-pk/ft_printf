# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 23:24:57 by raica-ba          #+#    #+#              #
#    Updated: 2025/01/13 15:07:35 by raica-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

INCLUDES = .

FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_FILES = conversion_functions.c unsigned_functions.c ft_printf.c utility_functions.c\

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
				@ar rcs $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
				$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				echo "Removing $(OBJ_DIR)"
				rm -rf $(OBJ_DIR)
fclean: clean
				echo "Removing $(NAME)"
				rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
