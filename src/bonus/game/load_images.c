/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:12:01 by roespici          #+#    #+#             */
/*   Updated: 2024/07/02 17:31:35 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static int	ft_load_images_map(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
		"assets/wall.xpm", &game->img_width, &game->img_height);
	game->img_water = mlx_xpm_file_to_image(game->mlx, \
		"assets/water.xpm", &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
		"assets/floor.xpm", &game->img_width, &game->img_height);
	game->img_blade = mlx_xpm_file_to_image(game->mlx, \
		"assets/blade.xpm", &game->img_width, &game->img_height);
	game->img_shield = mlx_xpm_file_to_image(game->mlx, \
		"assets/shield.xpm", &game->img_width, &game->img_height);
	if (!game->img_wall || !game->img_water || !game->img_floor || \
		!game->img_blade || !game->img_shield)
		return (FAILURE);
	return (SUCCESS);
}

static int	ft_load_collects(t_game *game)
{
	game->img_collect[0] = mlx_xpm_file_to_image(game->mlx, \
		"assets/collect1.xpm", &game->img_width, &game->img_height);
	game->img_collect[1] = mlx_xpm_file_to_image(game->mlx, \
		"assets/collect2.xpm", &game->img_width, &game->img_height);
	game->img_collect[2] = mlx_xpm_file_to_image(game->mlx, \
		"assets/collect3.xpm", &game->img_width, &game->img_height);
	game->img_collect[3] = mlx_xpm_file_to_image(game->mlx, \
		"assets/collect4.xpm", &game->img_width, &game->img_height);
	game->img_collect[4] = mlx_xpm_file_to_image(game->mlx, \
		"assets/collect5.xpm", &game->img_width, &game->img_height);
	game->img_collect[5] = mlx_xpm_file_to_image(game->mlx, \
		"assets/collect6.xpm", &game->img_width, &game->img_height);
	game->img_collect[6] = mlx_xpm_file_to_image(game->mlx, \
		"assets/collect7.xpm", &game->img_width, &game->img_height);
	if (!game->img_collect[0] || !game->img_collect[1] || \
		!game->img_collect[2] || !game->img_collect[3] || \
		!game->img_collect[4] || !game->img_collect[5] || !game->img_collect[6])
		return (FAILURE);
	return (SUCCESS);
}

static int	ft_load_images_ui(t_game *game)
{
	game->img_life_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/full_heart.xpm", &game->img_width, &game->img_height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, \
		"assets/empty_heart.xpm", &game->img_width, &game->img_height);
	game->img_victory = mlx_xpm_file_to_image(game->mlx, \
		"assets/victory.xpm", &game->img_width, &game->img_height);
	game->img_defeat = mlx_xpm_file_to_image(game->mlx, \
		"assets/defeat.xpm", &game->img_width, &game->img_height);
	game->img_defeat2 = mlx_xpm_file_to_image(game->mlx, \
		"assets/cost.xpm", &game->img_width, &game->img_height);
	if (!game->img_life_player || !game->img_empty || !game->img_victory || \
		!game->img_defeat || !game->img_defeat2)
		return (FAILURE);
	return (SUCCESS);
}

static int	ft_load_images_ennemy(t_game *game)
{
	if (game->ennemy_exist == 1)
	{
		game->img_ennemy = mlx_xpm_file_to_image(game->mlx, \
			"assets/ganon_s.xpm", &game->img_width, &game->img_height);
		game->img_ennemy_direction[0] = mlx_xpm_file_to_image(game->mlx, \
			"assets/ganon_a.xpm", &game->img_width, &game->img_height);
		game->img_ennemy_direction[1] = mlx_xpm_file_to_image(game->mlx, \
			"assets/ganon_d.xpm", &game->img_width, &game->img_height);
		game->img_ennemy_direction[2] = mlx_xpm_file_to_image(game->mlx, \
			"assets/ganon_s.xpm", &game->img_width, &game->img_height);
		game->img_ennemy_direction[3] = mlx_xpm_file_to_image(game->mlx, \
			"assets/ganon_w.xpm", &game->img_width, &game->img_height);
		if (!game->img_ennemy || !game->img_ennemy_direction[0] || \
			!game->img_ennemy_direction[1] || !game->img_ennemy_direction[2] || \
			!game->img_ennemy_direction[3])
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_load_images(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s.xpm", &game->img_width, &game->img_height);
	game->img_player_dead = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_dead.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
		"assets/exit.xpm", &game->img_width, &game->img_height);
	game->img_dead = mlx_xpm_file_to_image(game->mlx, \
		"assets/dead.xpm", &game->img_width, &game->img_height);
	game->img_epona = mlx_xpm_file_to_image(game->mlx, \
		"assets/epona_dead.xpm", &game->img_width, &game->img_height);
	if (!game->img_player || !game->img_player_dead || \
		!game->img_exit || !game->img_dead || !game->img_epona || \
		ft_load_images_map(game) == FAILURE || \
		ft_load_images_ui(game) == FAILURE || \
		ft_load_collects(game) == FAILURE || \
		ft_load_images_ennemy(game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
