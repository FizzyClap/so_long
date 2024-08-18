NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
LIBFT = libft/libft.a
LIBFT_PATH = ./libft
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
MLX_PATH = ./mlx
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lbsd -lXext -lX11 -lm
SDL_PATH = ./sound
SDL_FLAGS = -L$(SDL_PATH)/SDL2/build/.libs -L$(SDL_PATH)/SDL2_mixer/build/.libs -lSDL2 -lSDL2_mixer
INCLUDES = -I./includes -I$(MLX_PATH) -I./libft -I$(SDL_PATH)/SDL2/include -I$(SDL_PATH)/SDL2_mixer/include
RM = rm -rf
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[38;5;153m
NC = \033[0m

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

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Compiling $(NAME) in progress..."
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(INCLUDES)
	@echo "$(GREEN)Compilation of $(NAME) completed!"

.c.o:
	@$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)|| \
	{ echo "$(RED)Compiling of $< failed, FF."; exit 1; }

all: $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

mlx:
	@git clone https://github.com/42Paris/minilibx-linux mlx
	@echo "$(BLUE)Compilating mlx in progress..."
	@cd mlx && make -s
	@echo "$(GREEN)Compilation of Mlx completed!"

sdl:
	@cd sound && wget https://github.com/libsdl-org/SDL/releases/download/release-2.28.5/SDL2-2.28.5.tar.gz > /dev/null 2>&1
	@cd sound && tar -xvf SDL2-2.28.5.tar.gz > /dev/null 2>&1 && rm -rf SDL2-2.28.5.tar.gz
	@cd sound && mv SDL2-2.28.5 SDL2
	@echo "$(BLUE)Compiling SDL2 in progress..."
	@cd sound/SDL2 && ./configure > /dev/null 2>&1 && make -s > /dev/null 2>&1 || \
	{ echo "$(RED)Compiling SDL2 failed, FF."; exit 1; }
	@echo "$(GREEN)Compilation of SDL2 completed!"
	@cd sound && wget https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.8.0/SDL2_mixer-2.8.0.tar.gz > /dev/null 2>&1
	@cd sound && tar -xvf SDL2_mixer-2.8.0.tar.gz > /dev/null 2>&1 && rm -rf SDL2_mixer-2.8.0.tar.gz
	@cd sound && mv SDL2_mixer-2.8.0 SDL2_mixer
	@echo "$(BLUE)Compiling SDL2 Mixer in progress..."
	@cd sound/SDL2_mixer && ./configure > /dev/null 2>&1 && make -s > /dev/null 2>&1 || \
	{ echo "$(RED)Compiling SDL2 Mixer failed, FF."; exit 1; }
	@echo "$(GREEN)Compilation of SDL2 Mixer completed!"


bonus: clean $(OBJS_BONUS)
	@echo "$(BLUE)Compiling $(NAME_BONUS) in progress..."
	@$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(INCLUDES)
	@echo "$(GREEN)Compilation of $(NAME_BONUS) completed!"

music: FLAGS += -DMUSIC=1
music: clean $(OBJS_BONUS)
	@echo "$(BLUE)Compiling $(NAME_BONUS) with music in progress..."
	@$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(SDL_FLAGS) $(INCLUDES)
	@echo "$(GREEN)Compilation of $(NAME_BONUS) with music completed!"

clean:
	@echo "$(BLUE)Cleaning $(NAME) objects in progress..."
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$(GREEN)Cleaning of $(NAME) objects completed!"

fclean: clean
	@echo "$(BLUE)Cleaning $(NAME) and $(NAME_BONUS) in progress..."
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)Cleaning of $(NAME) and $(NAME_BONUS) completed!"
	@make -s -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
