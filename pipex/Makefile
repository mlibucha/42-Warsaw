# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Source files
CURRENT_DIR_SRCS = $(wildcard *.c)
SRC_DIR_SRCS = $(wildcard src/*.c)
ALL_SRCS = $(CURRENT_DIR_SRCS) $(SRC_DIR_SRCS)
OBJS = $(ALL_SRCS:.c=.o)

# Output executable
NAME = pipex

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
