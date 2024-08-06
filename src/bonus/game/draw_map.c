/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:02:01 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 15:21:16 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	ft_chose_collect(t_game *game)
{
	if (game->frame < 25)
		game->img = game->img_collect[0];
	else if (game->frame < 50)
		game->img = game->img_collect[1];
	else if (game->frame < 75)
		game->img = game->img_collect[2];
	else if (game->frame < 100)
		game->img = game->img_collect[3];
	else if (game->frame < 125)
		game->img = game->img_collect[4];
	else if (game->frame < 150)
		game->img = game->img_collect[5];
	else
		game->img = game->img_collect[6];
}

static void	ft_draw_pos(t_game *game, int x, int y)
{
	if (game->map->lines[y][x] == '1')
		game->img = game->img_wall;
	else if (game->map->lines[y][x] == 'H')
		game->img = game->img_life_player;
	else if (game->map->lines[y][x] == 'V')
		game->img = game->img_empty;
	else if (game->map->lines[y][x] == 'W')
		game->img = game->img_water;
	else if (game->map->lines[y][x] == '0')
		game->img = game->img_floor;
	else if (game->map->lines[y][x] == 'B')
		game->img = game->img_blade;
	else if (game->map->lines[y][x] == 'S')
		game->img = game->img_shield;
	else if (game->map->lines[y][x] == 'E')
		game->img = game->img_exit;
	else if (game->map->lines[y][x] == 'D')
		game->img = game->img_dead;
	else if (game->map->lines[y][x] == 'M')
		game->img = game->img_player_dead;
	else if (game->map->lines[y][x] == 'C')
		ft_chose_collect(game);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img, x * TILE_WIDTH, y * TILE_HEIGHT);
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
			ft_draw_pos(game, x, y);
	}
}
