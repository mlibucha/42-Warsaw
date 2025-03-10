# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Path to the minilibx-linux directory (relative to the Makefile)
MLX_DIR = ./minilibx-linux

# Include directory for mlx.h
INCLUDES = -I$(MLX_DIR)

# Source files (all .c files in the current directory)
SRCS = $(wildcard *.c)

# Object files (one .o file for each .c file)
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = game

# Libraries to link (MiniLibX and X11 libraries)
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean