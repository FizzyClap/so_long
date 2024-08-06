/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:38:43 by roespici          #+#    #+#             */
/*   Updated: 2024/06/30 14:10:28 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ft_move_player_w_135(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w4 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w4 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w4 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w4.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_w_90(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w3 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w3 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w3 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w3.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_w_45(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w2 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w2 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w2 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w2.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_w_0(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w shield.xpm", &game->img_width, &game->img_height);
	}
	else
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_w.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_collision_w(t_game *game)
{
	if (game->map->lines[game->player_y - 1][game->player_x] != '1' && \
		game->map->lines[game->player_y - 1][game->player_x] != 'W')
	{
		game->player_y -= 1;
		game->total_move = game->total_move + 1;
	}
}
