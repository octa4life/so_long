# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 14:07:11 by obellil-          #+#    #+#              #
#    Updated: 2025/05/06 14:09:19 by obellil-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fPIC -g3
RM		= rm -f

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
NC = \033[0m # No Color

SRC_DIR	= src
OBJ_DIR	= objs
INC_DIR	= includes

# MLX settings
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext

# Sources files
_SRCS = set_up_map.c utils.c parsing_so_long.c main.c mouv.c other.c displays.c
SRCS = $(addprefix $(SRC_DIR)/, $(_SRCS))

_OBJS = $(_SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(_OBJS))

# Path to libft library
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/gnl/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)>>> Compilation de libft <<<$(DEF_COLOR)"
	$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(GREEN)>>> libft.a créé avec succès <<<$(DEF_COLOR)"

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -sC $(LIBFT_DIR)
	$(MAKE) clean -sC $(MLX_DIR)
	@echo "$(GREEN)Object files cleaned!🧹​$(NC)"

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -sC $(LIBFT_DIR)
	$(MAKE) clean -sC $(MLX_DIR)
	@echo "$(GREEN)All files cleaned! 🧹​$(NC)"

re:	fclean all
	@echo "$(GREEN)>>> Cleaned and rebuilt everything for PIPEX ! 💯​ <<<$(DEF_COLOR)"
bonus: re

test: all
	./$(NAME)

.PHONY:	all clean fclean re
