/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:41:24 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 15:20:17 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/includes/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# define ESC 65307
# define GAUCHE 65361
# define HAUT 65362
# define DROITE 65363
# define BAS 65364
# define A 97
# define W 119
# define D 100
# define S 115
# define SUCCESS 1
# define FAILURE 0
# define VICTORY 1
# define TILE_WIDTH 103
# define TILE_HEIGHT 128

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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*addr;
	void	*img;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_player;
	void	*img_player_direction[4];
	void	*img_exit;
	char	*path;
	t_map	*map;
	int		player_x;
	int		player_y;
	char	player_direction;
	int		prev_x;
	int		prev_y;
	int		player_move;
	int		total_move;
	int		img_height;
	int		img_width;
}	t_game;

t_map	*ft_readmap(const char *path);
t_map	*ft_init_map(t_map *map);
void	ft_count_elements(t_map *map, char position);
int		ft_char_isvalid(char position);
void	ft_print_error(void);
int		ft_openmap(const char *path);
int		ft_map_isvalid(t_map *map, const char *path);
int		ft_keycode_isvalid(int keycode);
void	ft_side(int keycode, t_game *game);
void	ft_up_down(int keycode, t_game *game);
void	ft_floodfill_start(t_map *map);
int		ft_check_isvalid(t_map *map);
int		ft_close_game(t_game *game);
void	ft_update_map(t_game *game);
int		ft_load_images(t_game *game);
int		ft_keycode(int keycode, t_game *game);
void	ft_draw_map(t_game *game);
void	ft_game_start(t_game *game);
void	ft_free_game(t_game *game);
void	ft_free_images(t_game *game);
void	ft_free_map(t_map *map);

#endif
