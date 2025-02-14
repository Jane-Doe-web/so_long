NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I . -I $(SOURCES_DIR) -I $(BONUS_DIR) -I $(GET_NEXT_LINE_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
LIBFT_DIR = libft
GET_NEXT_LINE_DIR = get_next_line
MLX_DIR = mlx_linux
SOURCES_DIR = sources
BONUS_DIR = bonus

SRCS = $(SOURCES_DIR)/main.c $(SOURCES_DIR)/validate_map.c $(SOURCES_DIR)/read_map.c \
       $(SOURCES_DIR)/validate_path.c $(SOURCES_DIR)/render_map.c $(SOURCES_DIR)/handle_moves.c \
       $(SOURCES_DIR)/free.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(BONUS_DIR)/main_bonus.c $(BONUS_DIR)/validate_map_bonus.c $(BONUS_DIR)/read_map_bonus.c \
             $(BONUS_DIR)/validate_path_bonus.c $(BONUS_DIR)/render_map_bonus.c $(BONUS_DIR)/handle_moves_bonus.c \
             $(BONUS_DIR)/free_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

GET_NEXT_LINE_SRCS = $(GET_NEXT_LINE_DIR)/get_next_line.c $(GET_NEXT_LINE_DIR)/get_next_line_utils.c
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRCS:.c=.o)

HEADER = $(SOURCES_DIR)/so_long.h
HEADER_BONUS = $(BONUS_DIR)/so_long_bonus.h

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(GET_NEXT_LINE_DIR)/%.o: $(GET_NEXT_LINE_DIR)/%.c $(GET_NEXT_LINE_DIR)/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the executable
$(NAME): $(OBJS) $(GET_NEXT_LINE_OBJS) $(LIBFT_DIR)/libft.a $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(GET_NEXT_LINE_OBJS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS) $(GET_NEXT_LINE_OBJS) $(LIBFT_DIR)/libft.a $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GET_NEXT_LINE_OBJS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -o $(NAME_BONUS)

# Rule to compile the main sources
$(SOURCES_DIR)/%.o: $(SOURCES_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS) $(GET_NEXT_LINE_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(LIBFT_DIR)/libft.a

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus

