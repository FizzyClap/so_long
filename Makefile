NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
LIBFT_PATH = ./libft
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
MLX_PATH = ./mlx
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lbsd -lXext -lX11 -lm
SDL_PATH = ./sound
SDL_FLAGS = -L$(SDL_PATH)/SDL2/build/.libs -L$(SDL_PATH)/SDL2_mixer/build/.libs -lSDL2 -lSDL2_mixer
INCLUDES = -I./includes -I$(MLX_PATH) -I./libft -I$(SDL_PATH)/SDL2/include -I$(SDL_PATH)/SDL2_mixer/include
RM = rm -rf

SRCS =	src/mandatory/main.c\
		src/mandatory/utils/free.c\
		src/mandatory/game/so_long.c\
		src/mandatory/game/draw_utils.c\
		src/mandatory/parsing/parsing.c\
		src/mandatory/parsing/parsing_utils.c\
		src/mandatory/parsing/utils.c\

SRCS_BONUS =	src/bonus/main.c\
				src/bonus/utils/free.c\
				src/bonus/game/so_long_bonus.c\
				src/bonus/game/draw_map.c\
				src/bonus/game/ennemy.c\
				src/bonus/game/interface.c\
				src/bonus/game/init_game.c\
				src/bonus/game/kill.c\
				src/bonus/game/load_images.c\
				src/bonus/game/move_a.c\
				src/bonus/game/move_d.c\
				src/bonus/game/move_s.c\
				src/bonus/game/move_w.c\
				src/bonus/game/move_player.c\
				src/bonus/game/sound.c\
				src/bonus/parsing/parsing_bonus.c\
				src/bonus/parsing/parsing_utils_bonus.c\
				src/bonus/parsing/utils_bonus.c\

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(INCLUDES)

.c.o:
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)

all: $(NAME)

mlx:
	@wget https://cdn.intra.42.fr/document/document/21354/minilibx-linux.tgz
	@tar -xvf minilibx-linux.tgz && rm -rf minilibx-linux.tgz
	@mv minilibx-linux mlx
	@cd mlx && make && clear

sdl:
	@cd sound && wget https://github.com/libsdl-org/SDL/releases/download/release-2.28.5/SDL2-2.28.5.tar.gz
	@cd sound && tar -xvf SDL2-2.28.5.tar.gz && rm -rf SDL2-2.28.5.tar.gz
	@cd sound && mv SDL2-2.28.5 SDL2
	@cd sound/SDL2 && ./configure && make
	@cd sound && wget https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.8.0/SDL2_mixer-2.8.0.tar.gz
	@cd sound && tar -xvf SDL2_mixer-2.8.0.tar.gz && rm -rf SDL2_mixer-2.8.0.tar.gz
	@cd sound && mv SDL2_mixer-2.8.0 SDL2_mixer
	@cd sound/SDL2_mixer && ./configure && make && clear

bonus: clean $(OBJS_BONUS)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(INCLUDES)

music: FLAGS += -DMUSIC=1
music: clean $(OBJS_BONUS)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(SDL_FLAGS) $(INCLUDES)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
