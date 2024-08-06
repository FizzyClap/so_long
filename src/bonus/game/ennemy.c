/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:02:59 by roespici          #+#    #+#             */
/*   Updated: 2024/07/02 17:09:17 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	ft_update_loot(t_game *game)
{
	if (game->map->lines[game->ennemy_y][game->ennemy_x] == 'C')
		game->loot = 1;
	game->map->lines[game->ennemy_y][game->ennemy_x] = 'G';
}

static void	ft_ennemy_chose_side(t_game *game)
{
	if (game->map->lines[game->ennemy_y][game->ennemy_x - 1] != '1' && \
		game->map->lines[game->ennemy_y + 1][game->ennemy_x] != '1')
	{
		game->img_ennemy = game->img_ennemy_direction[0];
		game->ennemy_x -= 1;
		game->ennemy_direction = 'a';
	}
	else if (game->map->lines[game->ennemy_y + 1][game->ennemy_x] != '1')
	{
		game->img_ennemy = game->img_ennemy_direction[2];
		game->ennemy_y += 1;
		game->ennemy_direction = 's';
	}
	else if (game->map->lines[game->ennemy_y][game->ennemy_x + 1] != '1')
	{
		game->img_ennemy = game->img_ennemy_direction[1];
		game->ennemy_x += 1;
		game->ennemy_direction = 'd';
	}
	else if (game->map->lines[game->ennemy_y][game->ennemy_x] != '1')
	{
		game->img_ennemy = game->img_ennemy_direction[3];
		game->ennemy_y -= 1;
		game->ennemy_direction = 'w';
	}
}

static void	ft_ennemy_move(t_game *game)
{
	if (game->map->lines[game->ennemy_y][game->ennemy_x - 1] != '1' && \
		game->map->lines[game->ennemy_y + 1][game->ennemy_x] != '1')
	{
		ft_ennemy_chose_side(game);
		ft_update_loot(game);
	}
	else if (game->map->lines[game->ennemy_y + 1][game->ennemy_x] != '1')
	{
		ft_ennemy_chose_side(game);
		ft_update_loot(game);
	}
	else if (game->map->lines[game->ennemy_y][game->ennemy_x + 1] != '1')
	{
		ft_ennemy_chose_side(game);
		ft_update_loot(game);
	}
	else if (game->map->lines[game->ennemy_y][game->ennemy_x] != '1')
	{
		ft_ennemy_chose_side(game);
		ft_update_loot(game);
	}
}

int	ft_ennemy(t_game *game)
{
	if (game->life_ennemy == 1 && game->ennemy_exist == 1)
	{
		if (game->ennemy_move == 0)
		{
			mlx_destroy_image(game->mlx, game->img_ennemy);
			game->ennemy_move = 1;
		}
		game->map->lines[game->prev_ennemy_y][game->prev_ennemy_x] = '0';
		ft_ennemy_move(game);
		ft_condition_defeat(game);
	}
	else if (game->life_ennemy == 0 && game->loot == 1)
	{
		game->map->lines[game->ennemy_y][game->ennemy_x] = 'D';
		if (game->map->lines[game->ennemy_y][game->ennemy_x + 1] == '1')
			game->map->lines[game->ennemy_y][game->ennemy_x - 1] = 'C';
		else
			game->map->lines[game->ennemy_y][game->ennemy_x + 1] = 'C';
		game->loot = -1;
	}
	else if (game->life_ennemy == 0 && game->loot == 0)
		game->map->lines[game->ennemy_y][game->ennemy_x] = 'D';
	return (SUCCESS);
}
