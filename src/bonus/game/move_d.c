/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:37:00 by roespici          #+#    #+#             */
/*   Updated: 2024/06/30 14:10:28 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ft_move_player_d_135(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d4 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d4 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d4 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d4.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_d_90(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d3 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d3 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d3 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d3.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_d_45(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d2 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d2 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d2 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d2.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_d_0(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d shield.xpm", &game->img_width, &game->img_height);
	}
	else
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_d.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_collision_d(t_game *game)
{
	if ((game->state == VICTORY) || \
		(game->map->lines[game->player_y][game->player_x + 1] != '1' && \
		game->map->lines[game->player_y][game->player_x + 1] != 'W'))
	{
		game->player_x += 1;
		game->total_move = game->total_move + 1;
	}
}
