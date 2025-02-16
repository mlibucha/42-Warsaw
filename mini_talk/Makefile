# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC_CLIENT = client.c $(SRC_COMMON)
SRC_SERVER = server.c $(SRC_COMMON)

# Headers
HEADERS = ft_printf.h

# Printf Library
PRINTF_DIR = print-f
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

# Objects
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Executables
NAME_CLIENT = client
NAME_SERVER = server

# Rules
all: $(PRINTF_LIB) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF_LIB) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF_LIB) -o $(NAME_SERVER)

# Rule to compile .c files into .o files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Build Printf Library
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
