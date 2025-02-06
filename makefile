NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC_DIR	= src
OBJ_DIR	= objs
INC_DIR	= includes

# MLX settings
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext

# Sources files
_SRCS = main.c parsing.c parsing_utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(_SRCS))

_OBJS = $(_SRCS:.c=.o) $(GNL_SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(_OBJS))

# Path to libft library
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/gnl/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

re:	fclean all

bonus: re

test: all
	./$(NAME)

.PHONY:	all clean fclean re bonus test
