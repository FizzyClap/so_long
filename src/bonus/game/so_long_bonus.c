/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:09:14 by roespici          #+#    #+#             */
/*   Updated: 2024/06/11 07:51:34 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ft_condition_defeat(t_game *game)
{
	if (game->player_x == game->ennemy_x && \
		game->player_y == game->ennemy_y && game->life_ennemy == 1)
	{
		if (game->life_player == 2)
		{
			game->life_player++;
			if (game->map->lines[game->player_y - 2][game->player_x] == '1' || \
				game->map->lines[game->player_y - 2][game->player_x] == 'W')
			{
				game->player_x -= 1;
				game->player_y -= 1;
			}
			else
				game->player_y -= 2;
		}
		else if (game->life_player == 1 || game->life_player == 3)
		{
			game->map->lines[game->player_y - 1][game->player_x] = 'M';
			ft_update_display(game);
			mlx_do_sync(game->mlx);
			sleep(2);
			game->state = DEFEAT;
		}
	}
}

static void	ft_condition_victory(t_game *game)
{
	if ((game->map->lines[game->player_y][game->player_x] == 'E' && \
		game->map->collects == 0))
	{
		game->state = VICTORY;
		if (MUSIC)
		{
			game->event = 2;
			ft_sound(game);
		}
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"assets/galop_1.xpm", &game->img_width, &game->img_height);
	}
}

static void	ft_sound_collect(t_game *game)
{
	if (MUSIC)
	{
		if (game->map->collects == 0 && \
			game->map->lines[game->player_y][game->player_x] == 'C')
		{
			ft_update_display(game);
			mlx_do_sync(game->mlx);
			game->event = 1;
			ft_sound(game);
			game->event = 0;
			ft_sound(game);
		}
	}
}

int	ft_keycode(int keycode, t_game *game)
{
	if (ft_keycode_isvalid(keycode) == SUCCESS)
	{
		if (keycode == ESC)
			ft_close_game(game);
		ft_side(keycode, game);
		ft_up_down(keycode, game);
		ft_kill(keycode, game);
		if (game->map->lines[game->player_y][game->player_x] == 'B')
			game->blade = 1;
		if (game->map->lines[game->player_y][game->player_x] == 'S')
			game->life_player = 2;
		if ((game->map->lines[game->player_y][game->player_x] == 'C' && \
			game->map->collects--) || game->map->lines[game->player_y] \
			[game->player_x] == 'S' || game->map->lines[game->player_y] \
			[game->player_x] == 'B')
		{
			if (MUSIC)
				ft_sound_collect(game);
			game->map->lines[game->player_y][game->player_x] = '0';
		}
		ft_condition_defeat(game);
		ft_condition_victory(game);
	}
	return (SUCCESS);
}

int	ft_frame(t_game *game)
{
	game->frame++;
	if (game->frame > 180)
		game->frame = 0;
	return (game->frame);
}
