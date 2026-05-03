NAME	= so_long
NAME_BONUS	= so_long_bonus
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_LDFLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I. -Ift_printf -Iget_next_line -I$(MLX_DIR)

SRCS	= src/main.c src/map.c src/validate_setup.c \
		  src/validate_counts.c src/validate_path.c src/move.c src/utils.c \
		  src/draw.c src/close.c \
		  ft_printf/ft_printf.c ft_printf/ft_hex.c ft_printf/utilities.c \
		  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		  get_next_line/get_next_line_stash.c
OBJS	= $(SRCS:.c=.o)

SRCS_BONUS	= src_bonus/main_bonus.c src_bonus/map_bonus.c \
			src_bonus/validate_setup_bonus.c \
			src_bonus/validate_counts_bonus.c src_bonus/validate_path_bonus.c \
			src_bonus/move_bonus.c src_bonus/utils_bonus.c src_bonus/draw_bonus.c \
			src_bonus/close_bonus.c src_bonus/bonus_loop_bonus.c \
			src_bonus/bonus_enemy_bonus.c src_bonus/bonus_enemy_init_bonus.c \
			src_bonus/bonus_hud_bonus.c \
			ft_printf/ft_printf.c ft_printf/ft_hex.c ft_printf/utilities.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line_stash.c
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR) -f Makefile.gen

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LDFLAGS) -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_LDFLAGS) -o $@

src/%.o: src/%.c src/so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -Isrc -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Isrc -c $< -o $@

src_bonus/%.o: src_bonus/%.c src_bonus/so_long_bonus.h
	$(CC) $(CFLAGS) $(INCLUDES) -Isrc -Isrc_bonus -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS) src/*.o src_bonus/*.o

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
