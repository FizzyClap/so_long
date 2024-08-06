/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:38:10 by roespici          #+#    #+#             */
/*   Updated: 2024/06/30 14:10:28 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ft_move_player_s_135(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s4 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s4 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s4 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 135)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s4.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_s_90(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s3 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s3 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s3 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 90)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s3.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_s_45(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s2 both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s2 sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2 && game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s2 shield.xpm", &game->img_width, &game->img_height);
	}
	else if (game->frame >= 45)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s2.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_move_player_s_0(t_game *game)
{
	if (game->blade == 1 && game->life_player == 2)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s both.xpm", &game->img_width, &game->img_height);
	}
	else if (game->blade == 1)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s sword.xpm", &game->img_width, &game->img_height);
	}
	else if (game->life_player == 2)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s shield.xpm", &game->img_width, &game->img_height);
	}
	else
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"assets/link/link_s.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_collision_s(t_game *game)
{
	if (game->map->lines[game->player_y + 1][game->player_x] != '1' && \
		game->map->lines[game->player_y + 1][game->player_x] != 'W')
	{
		game->player_y += 1;
		game->total_move = game->total_move + 1;
	}
}
