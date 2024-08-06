/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:31:52 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 09:25:23 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

int	ft_keycode_isvalid(int keycode)
{
	if (keycode == ESC || keycode == GAUCHE || keycode == A || \
		keycode == DROITE || keycode == D || keycode == BAS || keycode == S || \
		keycode == HAUT || keycode == W || keycode == SPACE)
		return (SUCCESS);
	return (FAILURE);
}

static void	ft_ride_horse(t_game *game)
{
	if (game->state == VICTORY)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		if (game->map->lines[game->player_y][game->player_x + 1] == '1')
			game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"assets/galop_4.xpm", &game->img_width, &game->img_height);
		else if (game->frame >= 120)
			game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"assets/galop_3.xpm", &game->img_width, &game->img_height);
		else if (game->frame >= 60)
			game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"assets/galop_2.xpm", &game->img_width, &game->img_height);
		else
			game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"assets/galop_1.xpm", &game->img_width, &game->img_height);
	}
}

void	ft_side(int keycode, t_game *game)
{
	if ((keycode == GAUCHE || keycode == A) && (game->state == IN_PROGRESS))
	{
		ft_move_player_a_0(game);
		ft_move_player_a_45(game);
		ft_move_player_a_90(game);
		ft_move_player_a_135(game);
		ft_collision_a(game);
		game->player_direction = 'a';
	}
	if (keycode == DROITE || keycode == D)
	{
		if (game->state == IN_PROGRESS)
		{
			ft_move_player_d_0(game);
			ft_move_player_d_45(game);
			ft_move_player_d_90(game);
			ft_move_player_d_135(game);
		}
		ft_ride_horse(game);
		ft_collision_d(game);
		game->player_direction = 'd';
	}
}

void	ft_up_down(int keycode, t_game *game)
{
	if ((keycode == BAS || keycode == S) && (game->state == IN_PROGRESS))
	{
		ft_move_player_s_0(game);
		ft_move_player_s_45(game);
		ft_move_player_s_90(game);
		ft_move_player_s_135(game);
		ft_collision_s(game);
		game->player_direction = 's';
	}
	if ((keycode == HAUT || keycode == W) && (game->state == IN_PROGRESS))
	{
		ft_move_player_w_0(game);
		ft_move_player_w_45(game);
		ft_move_player_w_90(game);
		ft_move_player_w_135(game);
		ft_collision_w(game);
		game->player_direction = 'w';
	}
}
