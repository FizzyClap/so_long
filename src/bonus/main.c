/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:04:16 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 15:45:13 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_print_error();
	game = ft_calloc(1, sizeof(t_game));
	game->map = ft_readmap(argv[1]);
	if (game->map && ft_map_isvalid(game->map, argv[1]) == SUCCESS)
	{
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, TILE_WIDTH * game->map->x, \
			TILE_HEIGHT * game->map->y, "so_long_bonus");
		ft_game_start(game);
		if (ft_load_images(game) == FAILURE)
		{
			write(2, "Error\nPath to asset doesn't exist\n", 35);
			ft_close_game(game);
		}
		mlx_hook(game->win, 2, 1L << 0, ft_keycode, game);
		mlx_hook(game->win, 17, 0, ft_close_game, game);
		mlx_loop_hook(game->mlx, ft_loop, game);
		mlx_loop(game->mlx);
	}
	else
		free(game);
}
