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

#include "../../../includes/so_long.h"

void	ft_side(int keycode, t_game *game)
{
	if (keycode == GAUCHE || keycode == A)
	{
		game->img_player = game->img_player_direction[0];
		game->player_direction = 'a';
		if (game->map->lines[game->player_y][game->player_x - 1] != '1')
		{
			game->player_x -= 1;
			game->total_move = game->total_move + 1;
			ft_printf("Total move : %d\n", game->total_move);
		}
	}
	if (keycode == DROITE || keycode == D)
	{
		game->img_player = game->img_player_direction[1];
		game->player_direction = 'd';
		if (game->map->lines[game->player_y][game->player_x + 1] != '1')
		{
			game->player_x += 1;
			game->total_move = game->total_move + 1;
			ft_printf("Total move : %d\n", game->total_move);
		}
	}
}

void	ft_up_down(int keycode, t_game *game)
{
	if (keycode == BAS || keycode == S)
	{
		game->img_player = game->img_player_direction[2];
		game->player_direction = 's';
		if (game->map->lines[game->player_y + 1][game->player_x] != '1')
		{
			game->player_y += 1;
			game->total_move = game->total_move + 1;
			ft_printf("Total move : %d\n", game->total_move);
		}
	}
	if (keycode == HAUT || keycode == W)
	{
		game->img_player = game->img_player_direction[3];
		game->player_direction = 'w';
		if (game->map->lines[game->player_y - 1][game->player_x] != '1')
		{
			game->player_y -= 1;
			game->total_move = game->total_move + 1;
			ft_printf("Total move : %d\n", game->total_move);
		}
	}
}

int	ft_keycode(int keycode, t_game *game)
{
	if (ft_keycode_isvalid(keycode) == SUCCESS)
	{
		if (keycode == ESC)
			ft_close_game(game);
		if (game->player_move == 0)
		{
			mlx_destroy_image(game->mlx, game->img_player);
			game->player_move = 1;
		}
		ft_side(keycode, game);
		ft_up_down(keycode, game);
		if (game->map->lines[game->player_y][game->player_x] == 'C' && \
				game->map->collects--)
			game->map->lines[game->player_y][game->player_x] = '0';
		if (game->map->lines[game->player_y][game->player_x] == 'E' && \
			game->map->collects == 0)
			ft_close_game(game);
		ft_update_map(game);
	}
	return (SUCCESS);
}

void	ft_game_start(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->y)
	{
		x = -1;
		while (++x < game->map->x)
		{
			if (game->map->lines[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				game->prev_x = x;
				game->prev_y = y;
				game->map->lines[y][x] = '0';
			}
		}
	}
	game->total_move = 0;
	game->player_move = 0;
}
