/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:27:45 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 15:18:55 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

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

void	ft_free_images(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player && game->player_move == 0)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_player_direction[0])
		mlx_destroy_image(game->mlx, game->img_player_direction[0]);
	if (game->img_player_direction[1])
		mlx_destroy_image(game->mlx, game->img_player_direction[1]);
	if (game->img_player_direction[2])
		mlx_destroy_image(game->mlx, game->img_player_direction[2]);
	if (game->img_player_direction[3])
		mlx_destroy_image(game->mlx, game->img_player_direction[3]);
}
