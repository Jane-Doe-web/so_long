NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I$(SOURCES_DIR) -I$(BONUS_DIR) -I$(GET_NEXT_LINE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBFT_DIR = libft
GET_NEXT_LINE_DIR = get_next_line
MLX_DIR = mlx_linux
SOURCES_DIR = sources
BONUS_DIR = bonus

SRCS = $(SOURCES_DIR)/main.c $(SOURCES_DIR)/validate_map.c $(SOURCES_DIR)/read_map.c \
       $(SOURCES_DIR)/validate_path.c $(SOURCES_DIR)/render_map.c $(SOURCES_DIR)/handle_moves.c \
       $(SOURCES_DIR)/free.c
BONUS_SRCS = $(BONUS_DIR)/main_bonus.c $(BONUS_DIR)/validate_map_bonus.c $(BONUS_DIR)/read_map_bonus.c \
             $(BONUS_DIR)/validate_path_bonus.c $(BONUS_DIR)/render_map_bonus.c $(BONUS_DIR)/handle_moves_bonus.c \
             $(BONUS_DIR)/free_bonus.c $(BONUS_DIR)/handle_enemy_bonus.c $(BONUS_DIR)/initialize.c \
             $(BONUS_DIR)/win_lose_msg.c
GNL_SRCS = $(GET_NEXT_LINE_DIR)/get_next_line.c $(GET_NEXT_LINE_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS) $(GNL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
		make -C $(LIBFT_DIR) clean
		rm -f $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)

fclean: clean
		rm -f $(NAME) $(NAME_BONUS) $(LIBFT)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus