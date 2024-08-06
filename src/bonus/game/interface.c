/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:41:27 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 15:29:52 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	ft_draw_counter(t_game *game)
{
	char	*count_move;

	count_move = ft_itoa(game->total_move);
	if (!count_move)
		return ;
	mlx_string_put(game->mlx, game->win, game->map->x / 2 * game->img_width, \
		game->map->y * game->img_height, 0xFFFFFF, "MOVES : ");
	mlx_string_put(game->mlx, game->win, game->map->x / 2 * \
		game->img_width + 50, game->map->y * game->img_height, 0xFFFFFF, \
		count_move);
	free(count_move);
}

static void	ft_update_map(t_game *game)
{
	if (game->life_ennemy == 0 && game->ennemy_exist == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img_dead, \
			game->img_width * game->ennemy_x, \
			game->img_height * game->ennemy_y);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, \
	game->player_x * game->img_width, game->player_y * game->img_height);
	if (game->life_ennemy == 1 && game->ennemy_exist == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_ennemy, \
		game->ennemy_x * game->img_width, game->ennemy_y * game->img_height);
		game->prev_ennemy_x = game->ennemy_x;
		game->prev_ennemy_y = game->ennemy_y;
	}
	if (game->state == VICTORY && game->map->lines[game->player_y] \
		[game->player_x] == 'E')
		game->map->lines[game->player_y][game->player_x] = '0';
	if (game->life_epona == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_epona, \
			game->img_width * game->exit_x, game->img_height * game->exit_y);
		mlx_do_sync(game->mlx);
		sleep(1);
		game->state = DEFEAT;
	}
}

static void	ft_draw_ui(t_game *game)
{
	if (game->life_player == 2)
		game->map->lines[0][1] = 'H';
	if (game->life_player == 3)
		game->map->lines[0][1] = 'V';
	if (game->state == VICTORY && game->player_x == game->map->x)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_victory, 0, 0);
		mlx_do_sync(game->mlx);
		sleep(2);
		ft_close_game(game);
	}
	else if (game->state == DEFEAT)
	{
		if (MUSIC)
			ft_sound(game);
		if (game->life_epona == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_defeat2, \
			0, 0);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_defeat, \
			0, 0);
		mlx_do_sync(game->mlx);
		sleep(6);
		ft_close_game(game);
	}
}

void	ft_update_display(t_game *game)
{
	ft_draw_map(game);
	ft_update_map(game);
	ft_draw_ui(game);
	ft_draw_counter(game);
}

int	ft_loop(t_game *game)
{
	if (game->frame == 180)
		ft_ennemy(game);
	ft_frame(game);
	ft_update_display(game);
	return (SUCCESS);
}
