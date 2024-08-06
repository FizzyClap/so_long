/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:50:19 by roespici          #+#    #+#             */
/*   Updated: 2024/06/29 20:22:49 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

t_map	*ft_init_map(t_map *map)
{
	map->wall = 0;
	map->road = 0;
	map->collects = 0;
	map->player = 0;
	map->exit = 0;
	return (map);
}

void	ft_count_elements(t_map *map, char position)
{
	if (position == '1')
		map->wall++;
	else if (position == '0')
		map->road++;
	else if (position == 'C')
		map->collects++;
	else if (position == 'P')
		map->player++;
	else if (position == 'E')
		map->exit++;
}

void	ft_floodfill_start(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->lines[y][x] == 'P')
			{
				map->start_x = x;
				map->start_y = y;
			}
		}
	}
}

int	ft_char_isvalid(char position)
{
	if (position == '1' || position == '0' || position == 'C' || \
		position == 'P' || position == 'E')
		return (SUCCESS);
	else
		return (FAILURE);
}

int	ft_check_isvalid(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			ft_count_elements(map, map->lines[y][x]);
			if (ft_char_isvalid(map->lines[y][x]) == FAILURE)
			{
				write(2, "Error\nAn element of the map is not valid\n", 42);
				return (FAILURE);
			}
			if (map->lines[0][x] != '1' || map->lines[y][0] != '1' || \
				map->lines[map->y - 1][x] != '1' || \
				map->lines[y][map->x - 1] != '1')
			{
				write(2, "Error\nBordures aren't walls\n", 29);
				return (FAILURE);
			}
		}
	}
	return (SUCCESS);
}
