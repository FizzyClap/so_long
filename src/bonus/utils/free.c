/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:05:47 by roespici          #+#    #+#             */
/*   Updated: 2024/07/02 17:39:34 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->lines[++i])
		free(map->lines[i]);
	i = -1;
	while (map->copy[++i])
		free(map->copy[i]);
	free(map->copy);
	free(map->lines);
	free(map);
}

void	ft_free_game(t_game *game)
{
	if (game->map)
		ft_free_map(game->map);
	free(game);
}

static void	ft_free_items(t_game *game)
{
	if (game->img_collect[0])
		mlx_destroy_image(game->mlx, game->img_collect[0]);
	if (game->img_collect[1])
		mlx_destroy_image(game->mlx, game->img_collect[1]);
	if (game->img_collect[2])
		mlx_destroy_image(game->mlx, game->img_collect[2]);
	if (game->img_collect[3])
		mlx_destroy_image(game->mlx, game->img_collect[3]);
	if (game->img_collect[4])
		mlx_destroy_image(game->mlx, game->img_collect[4]);
	if (game->img_collect[5])
		mlx_destroy_image(game->mlx, game->img_collect[5]);
	if (game->img_collect[6])
		mlx_destroy_image(game->mlx, game->img_collect[6]);
	if (game->img_blade)
		mlx_destroy_image(game->mlx, game->img_blade);
	if (game->img_shield)
		mlx_destroy_image(game->mlx, game->img_shield);
}

static void	ft_free_ennemy(t_game *game)
{
	if (game->img_ennemy && game->ennemy_move == 0)
		mlx_destroy_image(game->mlx, game->img_ennemy);
	if ((game->img_ennemy_direction[0] && game->ennemy_direction != 'a') || \
		(game->img_ennemy_direction[0] && game->life_ennemy == 1))
		mlx_destroy_image(game->mlx, game->img_ennemy_direction[0]);
	if ((game->img_ennemy_direction[1] && game->ennemy_direction != 'd') || \
		(game->img_ennemy_direction[1] && game->life_ennemy == 1))
		mlx_destroy_image(game->mlx, game->img_ennemy_direction[1]);
	if ((game->img_ennemy_direction[2] && game->ennemy_direction != 's') || \
		(game->img_ennemy_direction[2] && game->life_ennemy == 1))
		mlx_destroy_image(game->mlx, game->img_ennemy_direction[2]);
	if ((game->img_ennemy_direction[3] && game->ennemy_direction != 'w') || \
		(game->img_ennemy_direction[3] && game->life_ennemy == 1))
		mlx_destroy_image(game->mlx, game->img_ennemy_direction[3]);
	if (game->img_dead)
		mlx_destroy_image(game->mlx, game->img_dead);
	if (game->img_player_dead)
		mlx_destroy_image(game->mlx, game->img_player_dead);
}

void	ft_free_images(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_water)
		mlx_destroy_image(game->mlx, game->img_water);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_life_player)
		mlx_destroy_image(game->mlx, game->img_life_player);
	if (game->img_empty)
		mlx_destroy_image(game->mlx, game->img_empty);
	if (game->img_exit && game->life_epona == 1)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_epona)
		mlx_destroy_image(game->mlx, game->img_epona);
	if (game->img_victory)
		mlx_destroy_image(game->mlx, game->img_victory);
	if (game->img_defeat)
		mlx_destroy_image(game->mlx, game->img_defeat);
	if (game->img_defeat2)
		mlx_destroy_image(game->mlx, game->img_defeat2);
	ft_free_items(game);
	ft_free_ennemy(game);
}
