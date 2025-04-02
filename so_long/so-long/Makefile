# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Executable Name
NAME = so_long

# Source Files (all .c files in the current directory)
SRCS = clean.c kys.c get_next_line_utils_bonus.c get_next_line_bonus.c lib.c main.c map_check.c map_check2.c map_ut.c map.c moves.c position.c render.c textures.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Headers
HEADERS = so_long.h

# MiniLibX Library
MLX_DIR = ./minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
MLX_INC = -I$(MLX_DIR)

# Printf Library
PRINTF_DIR = ./print-f
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

# Default target
all: $(MLX_DIR)/libmlx.a $(PRINTF_LIB) $(NAME)

# Build so_long
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB) -L$(PRINTF_DIR) -lftprintf

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) $(PRINTF_INC) -c $< -o $@

# Build MiniLibX
$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

# Build ft_printf
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

# Clean object files
clean:
	rm -f $(OBJS)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

# Remove executables and object files
fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)

# Rebuild everything
re: fclean all

# Phony targets (not actual files)
.PHONY: all clean fclean re

