/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:09:26 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/11 17:39:52 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	update_pos(t_map *map, char c, t_pos *pos)
{
	if (c == PLAYER && map->player == false)
	{
		map->player = true;
		map->s_pos = *pos;
	}
	else if (c == EXIT && map->end == false)
	{
		map->end = true;
		map->e_pos = *pos;
	}
	else if (c != WALL && c != FLOOR)
		p_error_map(MAP_PE_ERR, map);
}

static void	check_content(t_map *map, char c, t_pos *pos)
{
	if (c == WALL || c == FLOOR || c == PLAYER || c == EXIT)
		update_pos(map, c, pos);
	else if (c == COLLECTIBLES)
		map->collectibles++;
	else if (c == MOBS)
		map->mobs++;
	else
		p_error_map(MAP_CHAR_ERR, map);
}

static void	parse_map(t_map *map)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			check_content(map, map->map[pos.y][pos.x], &pos);
			pos.x++;
		}
		pos.y++;
	}
}

static void	content_checker(t_map *map)
{
	map->player = false;
	map->end = false;
	map->collectibles = 0;
	map->mobs = 0;
	parse_map(map);
	if (map->collectibles == 0)
		p_error_map(MAP_LEAST_C, map);
	else if (map->mobs == 0)
		p_error_map(MAP_LEAST_X, map);
	else if (!map->player)
		p_error_map(MAP_LEAST_P, map);
	else if (!map->end)
		p_error_map(MAP_LEAST_E, map);
}

void	map_checker(t_map *map)
{
	t_pos	pos;

	pos.x = 0;
	while (pos.x < map->width)
	{
		if (map->map[0][pos.x] != WALL
				|| map->map[map->height - 1][pos.x] != WALL)
			p_error_map(MAP_TOPBOT_ERR, map);
		pos.x++;
	}
	pos.y = 0;
	while (pos.y < map->height)
	{
		if (map->map[pos.y][0] != WALL
				|| map->map[pos.y][map->width - 1] != WALL)
			p_error_map(MAP_WALL_ERR, map);
		pos.y++;
	}
	content_checker(map);
	path_checker(map);
}
