/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:08:14 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 15:22:11 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	ft_init_game(t_game *game)
{
	game->frame = 0;
	game->state = IN_PROGRESS;
	game->loot = 0;
	game->blade = 0;
	game->life_player = 1;
	game->life_ennemy = 1;
	game->life_epona = 1;
	game->ennemy_move = 0;
	game->total_move = 0;
	game->ennemy_exist = 0;
	game->event = 0;
	if (MUSIC)
	{
		game->music = ft_calloc(1, sizeof(t_music));
		if (!game->music)
			return ;
		game->music->main = NULL;
		game->music->item = NULL;
		game->music->victory = NULL;
		game->music->defeat = NULL;
		ft_init_sound();
		ft_sound(game);
	}
}

static void	ft_start_pos(t_game *game, int x, int y)
{
	if (game->map->lines[y][x] == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->map->lines[y][x] = '0';
	}
	if (game->map->lines[y][x] == 'G')
	{
		game->ennemy_x = x;
		game->ennemy_y = y;
		game->ennemy_exist = 1;
	}
	if (game->map->lines[y][x] == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
	}
}

void	ft_game_start(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	ft_init_game(game);
	while (++y < game->map->y)
	{
		x = -1;
		while (++x < game->map->x)
			ft_start_pos(game, x, y);
	}
}
