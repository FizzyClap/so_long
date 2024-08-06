/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:31:52 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 15:09:54 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	ft_keycode_isvalid(int keycode)
{
	if (keycode == ESC || keycode == GAUCHE || keycode == A || \
		keycode == DROITE || keycode == D || keycode == BAS || \
		keycode == S || keycode == HAUT || keycode == W)
		return (SUCCESS);
	return (FAILURE);
}

void	ft_draw_map(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->map->y)
	{
		x = -1;
		while (++x < game->map->x)
		{
			if (game->map->lines[y][x] == '1')
				game->img = game->img_wall;
			else if (game->map->lines[y][x] == '0')
				game->img = game->img_floor;
			else if (game->map->lines[y][x] == 'C')
				game->img = game->img_collect;
			else if (game->map->lines[y][x] == 'E')
				game->img = game->img_exit;
			mlx_put_image_to_window(game->mlx, game->win, \
				game->img, x * game->img_width, y * game->img_height);
		}
	}
}

int	ft_load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
		"assets/wall.xpm", &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
		"assets/floor.xpm", &game->img_width, &game->img_height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, \
		"assets/collect1.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
		"assets/exit.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s.xpm", &game->img_width, &game->img_height);
	game->img_player_direction[0] = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_a.xpm", &game->img_width, &game->img_height);
	game->img_player_direction[1] = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d.xpm", &game->img_width, &game->img_height);
	game->img_player_direction[2] = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s.xpm", &game->img_width, &game->img_height);
	game->img_player_direction[3] = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w.xpm", &game->img_width, &game->img_height);
	if (!game->img_wall || !game->img_floor || !game->img_collect || \
		!game->img_exit || !game->img_player || !game->img_player_direction[0] \
		|| !game->img_player_direction[1] || !game->img_player_direction[2] || \
		!game->img_player_direction[3])
		return (FAILURE);
	return (SUCCESS);
}

void	ft_update_map(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, \
		game->prev_x * game->img_width, game->prev_y * game->img_height);
	if (game->map->lines[game->prev_y][game->prev_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, \
			game->prev_x * game->img_width, game->prev_y * game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, \
		game->player_x * game->img_width, game->player_y * game->img_height);
	game->prev_x = game->player_x;
	game->prev_y = game->player_y;
}
