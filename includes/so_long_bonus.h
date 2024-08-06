/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:05:24 by roespici          #+#    #+#             */
/*   Updated: 2024/08/06 10:32:49 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/includes/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/printf.h"
# include "../sound/SDL2_mixer/include/SDL_mixer.h"
# include "../sound/SDL2/include/SDL.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# define ESC 65307
# define GAUCHE 65361
# define HAUT 65362
# define DROITE 65363
# define BAS 65364
# define A 97
# define W 119
# define D 100
# define S 115
# define SPACE 32
# define BUFFER_SIZE 1
# define SUCCESS 1
# define FAILURE 0
# define IN_PROGRESS 0
# define VICTORY 1
# define DEFEAT 2
# define TILE_WIDTH 103
# define TILE_HEIGHT 128
# define WIN_WIDTH 1028
# define WIN_HEIGHT 720

# ifndef MUSIC
#  define MUSIC 0
# endif

typedef struct s_map
{
	char	**lines;
	char	**copy;
	int		x;
	int		y;
	int		wall;
	int		road;
	int		collects;
	int		player;
	int		exit;
	int		start_x;
	int		start_y;
}	t_map;

typedef struct s_music
{
	Mix_Music	*main;
	Mix_Music	*item;
	Mix_Music	*victory;
	Mix_Music	*defeat;
}	t_music;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*path;
	void		*img_wall;
	void		*img_floor;
	void		*img_water;
	void		*img_collect[9];
	void		*img_blade;
	void		*img_shield;
	void		*img_player;
	void		*img_player_dead;
	void		*img_ennemy;
	void		*img_ennemy_direction[4];
	void		*img_exit;
	void		*img_life_player;
	void		*img_empty;
	void		*img_epona;
	void		*img_dead;
	void		*img_victory;
	void		*img_defeat;
	void		*img_defeat2;
	int			player_x;
	int			player_y;
	char		player_direction;
	int			ennemy_x;
	int			ennemy_y;
	int			prev_ennemy_x;
	int			prev_ennemy_y;
	char		ennemy_direction;
	int			ennemy_move;
	int			exit_x;
	int			exit_y;
	int			total_move;
	int			img_height;
	int			img_width;
	int			blade;
	int			life_player;
	int			life_ennemy;
	int			life_epona;
	int			loot;
	int			state;
	int			frame;
	int			event;
	int			ennemy_exist;
	t_map		*map;
	t_camera	camera;
	t_music		*music;
}	t_game;

t_map	*ft_readmap(const char *path);
t_map	*ft_init_map(t_map *map);
void	ft_count_elements(t_map *map, char position);
int		ft_char_isvalid(char position);
void	ft_print_error(void);
int		ft_openmap(const char *path);
int		ft_map_isvalid(t_map *map, const char *path);
int		ft_roadexist(const char *path);
int		ft_keycode_isvalid(int keycode);
void	ft_side(int keycode, t_game *game);
void	ft_up_down(int keycode, t_game *game);
void	ft_floodfill_start(t_map *map);
int		ft_check_isvalid(t_map *map);
void	ft_free_game(t_game *game);
void	ft_free_map(t_map *map);
void	ft_free_images(t_game *game);
int		ft_load_images(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_update_display(t_game *game);
int		ft_ennemy(t_game *game);
int		ft_close_game(t_game *game);
void	ft_kill(int keycode, t_game *game);
void	ft_game_start(t_game *game);
void	ft_condition_defeat(t_game *game);
void	ft_move_player_a_135(t_game *game);
void	ft_move_player_a_90(t_game *game);
void	ft_move_player_a_45(t_game *game);
void	ft_move_player_a_0(t_game *game);
void	ft_collision_a(t_game *game);
void	ft_move_player_d_135(t_game *game);
void	ft_move_player_d_90(t_game *game);
void	ft_move_player_d_45(t_game *game);
void	ft_move_player_d_0(t_game *game);
void	ft_collision_d(t_game *game);
void	ft_move_player_s_135(t_game *game);
void	ft_move_player_s_90(t_game *game);
void	ft_move_player_s_45(t_game *game);
void	ft_move_player_s_0(t_game *game);
void	ft_collision_s(t_game *game);
void	ft_move_player_w_135(t_game *game);
void	ft_move_player_w_90(t_game *game);
void	ft_move_player_w_45(t_game *game);
void	ft_move_player_w_0(t_game *game);
void	ft_collision_w(t_game *game);
int		ft_loop(t_game *game);
int		ft_keycode(int keycode, t_game *game);
void	ft_init_camera(t_game *game);
void	ft_update_camera(t_game *game);
void	ft_sound(t_game *game);
void	ft_error_sdl(const char *message, Mix_Music *musique);
void	ft_init_sound(void);
void	ft_free_sound(t_game *game);
int		ft_frame(t_game *game);

#endif
