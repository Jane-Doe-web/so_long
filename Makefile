NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
GET_NEXT_LINE_DIR = get_next_line
MLX_DIR = mlx_linux

SRCS = main.c validate_map.c read_map.c validate_path.c render_map.c handle_moves.c free.c
OBJS = $(SRCS:.c=.o)

GET_NEXT_LINE_SRCS = $(GET_NEXT_LINE_DIR)/get_next_line.c $(GET_NEXT_LINE_DIR)/get_next_line_utils.c
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRCS:.c=.o)

all: $(NAME)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(GET_NEXT_LINE_DIR)/%.o: $(GET_NEXT_LINE_DIR)/%.c
	$(CC) $(CFLAGS) -I $(GET_NEXT_LINE_DIR) -c $< -o $@

# Rule to build the executable
$(NAME): $(OBJS) $(GET_NEXT_LINE_OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(GET_NEXT_LINE_OBJS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -o $(NAME)

# Rule to compile the main sources
%.o: %.c
	$(CC) $(CFLAGS) -I $(GET_NEXT_LINE_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR) -c $< -o $@

clean: 
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -f $(GET_NEXT_LINE_OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY: all clean fclean re 
