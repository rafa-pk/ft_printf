NAME = libftprintf.a

CC = cc

INCLUDES = .

FLAGS = -Wall -Werror -Wextra -g

OBJ_DIR = obj
SRC_DIR = src

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_FILES = ft_printf.c aux_functions.c\

EXEC = ft_printf

all: $(NAME) $(EXEC)
	
$(NAME): $(OBJ_DIR) $(OBJ)
		@ar rcs $@ $(OBJ)
		@ranlib $@

$(EXEC): $(OBJ)
		CC $(FLAGS) -o $(EXEC) $(OBJ)

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