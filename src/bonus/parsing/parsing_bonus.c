/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:43 by roespici          #+#    #+#             */
/*   Updated: 2024/06/29 20:21:11 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static t_map	*ft_getsize_map(const char *path)
{
	t_map	*map;
	char	*line;
	int		fd;

	fd = ft_openmap(path);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (close(fd), NULL);
	map->x = 0;
	map->y = 0;
	map->lines = NULL;
	map->copy = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (map->y == 0)
			map->x = ft_strlen(line) - 1;
		map->y++;
		free(line);
	}
	return (close(fd), map);
}

t_map	*ft_readmap(const char *path)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		i;

	fd = ft_openmap(path);
	if (fd == -1)
		return (NULL);
	map = ft_getsize_map(path);
	map->lines = ft_calloc(sizeof(char *), (map->y + 1));
	if (!map->lines)
		return (close(fd), NULL);
	map->copy = ft_calloc(sizeof(char *), (map->y + 1));
	if (!map->copy)
		return (close(fd), NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->lines[i] = line;
		map->copy[i++] = ft_strdup(line);
	}
	return (close(fd), map);
}

static void	ft_flood_fill(char **map_copy, int x, int y)
{
	if (x < 0 || y < 0 || !map_copy || map_copy[y][x] == '1' || \
	map_copy[y][x] == 'F' || map_copy[y][x] == 'H')
		return ;
	map_copy[y][x] = 'F';
	ft_flood_fill(map_copy, x + 1, y);
	ft_flood_fill(map_copy, x - 1, y);
	ft_flood_fill(map_copy, x, y + 1);
	ft_flood_fill(map_copy, x, y - 1);
}

int	ft_roadexist(const char *path)
{
	t_map	*tmp;
	int		x;
	int		y;

	tmp = ft_readmap(path);
	ft_init_map(tmp);
	ft_floodfill_start(tmp);
	if (tmp->start_x >= 0 && tmp->start_y >= 0)
		ft_flood_fill(tmp->copy, tmp->start_x, tmp->start_y);
	y = -1;
	while (++y < tmp->y)
	{
		x = -1;
		while (++x < tmp->x)
			ft_count_elements(tmp, tmp->copy[y][x]);
	}
	if (tmp->collects != 0 || tmp->player != 0 || tmp->exit != 0)
		return (ft_free_map(tmp), FAILURE);
	return (ft_free_map(tmp), SUCCESS);
}

int	ft_map_isvalid(t_map *map, const char *path)
{
	ft_init_map(map);
	if (ft_check_isvalid(map) == FAILURE)
		return (ft_free_map(map), FAILURE);
	if (map->collects < 1 || map->exit != 1 || map->player != 1)
	{
		write(2, "Error\nWrong number of components in the map\n", 45);
		return (ft_free_map(map), FAILURE);
	}
	if (ft_roadexist(path) == FAILURE)
	{
		write(2, "Error\nThere is no valable road to join the exit\n", 49);
		return (ft_free_map(map), FAILURE);
	}
	if (map->x == map->y)
	{
		write(2, "Error\nMap is square\n", 21);
		return (ft_free_map(map), FAILURE);
	}
	return (SUCCESS);
}
