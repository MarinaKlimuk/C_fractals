NAME = fractol

SOURCES =	events.c \
			init.c \
			main.c \
			math_utils.c \
			render.c \
			string_utils.c \

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror 

LDFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

OBJECTS = $(SOURCES:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

# Rule to create the executable
$(NAME): $(MLX_LIB) $(OBJECTS)
	$(COMPILER) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

$ (MLX_LIB):
	make -C $(MXL_DIR)

# Rule to compile each .c file into a .o file
%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re