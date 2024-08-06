/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:55:55 by roespici          #+#    #+#             */
/*   Updated: 2024/06/30 14:29:15 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	ft_kill_side(t_game *game)
{
	if (game->map->lines[game->player_y][game->player_x + 1] == 'G' && \
		game->blade == 1 && game->player_direction == 'd')
	{
		game->map->lines[game->player_y][game->player_x + 1] = '0';
		game->life_ennemy = 0;
		mlx_destroy_image(game->mlx, game->img_ennemy);
	}
	if (game->map->lines[game->player_y][game->player_x - 1] == 'G' && \
		game->blade == 1 && game->player_direction == 'a')
	{
		game->map->lines[game->player_y][game->player_x - 1] = '0';
		game->life_ennemy = 0;
		mlx_destroy_image(game->mlx, game->img_ennemy);
	}
	if (game->map->lines[game->player_y][game->player_x - 1] == 'E' && \
		game->blade == 1 && game->player_direction == 'a')
	{
		game->map->lines[game->player_y][game->player_x - 1] = '0';
		game->life_epona = 0;
		mlx_destroy_image(game->mlx, game->img_exit);
	}
}

static void	ft_kill_updown(t_game *game)
{
	if (game->map->lines[game->player_y + 1][game->player_x] == 'G' && \
		game->blade == 1 && game->player_direction == 's')
	{
		game->map->lines[game->player_y + 1][game->player_x] = '0';
		game->life_ennemy = 0;
		mlx_destroy_image(game->mlx, game->img_ennemy);
	}
	if (game->map->lines[game->player_y - 1][game->player_x] == 'G' && \
		game->blade == 1 && game->player_direction == 'w')
	{
		game->map->lines[game->player_y - 1][game->player_x] = '0';
		game->life_ennemy = 0;
		mlx_destroy_image(game->mlx, game->img_ennemy);
	}
}

void	ft_kill(int keycode, t_game *game)
{
	if (keycode == SPACE)
	{
		ft_kill_side(game);
		ft_kill_updown(game);
	}
}
