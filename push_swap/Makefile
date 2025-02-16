CC = cc
CFLAGS = -Wall -Wextra -Werror

# Executable Names
NAME = push_swap
CHECKER = checker

# Source Files
PUSH_SWAP_SRCS = cost.c create.c main.c errors.c opti.c libfun.c r_ops.c s_and_p.c so.c sort.c test.c 
CHECKER_SRCS = chcker.c get_next_line.c get_next_line_utils.c \
               s_and_p.c r_ops.c sort.c create.c libfun.c errors.c opti.c so.c cost.c test.c checkermain.c

# Object Files
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

# Headers
HEADERS = push_swap.h checker.h

# Printf Library
PRINTF_DIR = print-f
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

# Default target
all: $(NAME) $(CHECKER)

# Build push_swap
$(NAME): $(PUSH_SWAP_OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -o $(NAME) -L$(PRINTF_DIR) -lftprintf

# Build checker
$(CHECKER): $(CHECKER_OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER) -L$(PRINTF_DIR) -lftprintf

# Compile object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(PRINTF_INC) -c $< -o $@

# Build printf library
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

# Clean object files
clean:
	rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	make clean -C $(PRINTF_DIR)

# Remove executables and object files
fclean: clean
	rm -f $(NAME) $(CHECKER)
	make fclean -C $(PRINTF_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
