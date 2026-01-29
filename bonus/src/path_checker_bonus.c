/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:05:44 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 08:53:44 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	checker(t_map *map)
{
	if (map->collectibles != map->c_reach)
		p_error_double_map(COLL_ACC_ERR, map, map);
	if (map->mobs != map->m_reach)
		p_error_double_map(MOBS_ACC_ERR, map, map);
	if (map->e_reach == false)
		p_error_double_map(EXIT_ACC_ERR, map, map);
}

static void	flood_fill(t_map *map, t_pos current_pos)
{	
	if (current_pos.x < 0 || current_pos.x >= map->width
		|| current_pos.y < 0 || current_pos.y >= map->height)
		return ;
	if (map->map[current_pos.y][current_pos.x] == WALL ||
		map->path_grid[current_pos.y][current_pos.x] == VISITED)
		return ;
	map->path_grid[current_pos.y][current_pos.x] = VISITED;
	if (map->map[current_pos.y][current_pos.x] == COLLECTIBLES)
		map->c_reach++;
	else if (map->map[current_pos.y][current_pos.x] == MOBS)
		map->m_reach++;
	else if (map->map[current_pos.y][current_pos.x] == EXIT)
		map->e_reach = true;
	flood_fill(map, (t_pos){current_pos.x + 1, current_pos.y});
	flood_fill(map, (t_pos){current_pos.x -1, current_pos.y});
	flood_fill(map, (t_pos){current_pos.x, current_pos.y + 1});
	flood_fill(map, (t_pos){current_pos.x, current_pos.y - 1});
}

static void	init_path_grid(t_map *map)
{
	int	i;

	map->path_grid = (char **)malloc(sizeof(char *) * map->height);
	if (!map->path_grid)
		p_error_map(GRID_H_MAL_ERR, map);
	i = 0;
	while (i < map->height)
	{
		map->path_grid[i]
			= (char *)ft_calloc(map->width, sizeof(char));
		if (!map->path_grid[i])
			p_error_double_map(GRID_W_CAL_ERR, map, map);
		i++;
	}
	map->c_reach = 0;
	map->m_reach = 0;
	map->e_reach = false;
}

void	path_checker(t_map *map)
{
	init_path_grid(map);
	flood_fill(map, map->s_pos);
	checker(map);
	free_pathgrid(map);
}
