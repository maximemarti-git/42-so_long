/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:37:19 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 16:39:30 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	store_line(t_map *map, int fd)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			return (free_map(map),
				p_error(GNL_ERR));
		len = (int)ft_strlen(line);
		if (len > 0 && line[len -1] == '\n')
			line[--len] = '\0';
		if (len != map->width)
			return (close(fd), free(line),
				free_map(map),
				p_error(NOT_RECTANGULAR));
		map->map[i] = line;
		i++;
	}
}

static void	load_map(char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		p_error(NOT_FOUND);
	map->map = (char **)malloc(sizeof(char *) * map->height);
	if (!map->map)
		return (close(fd), p_error(MAP_MAL_ERR));
	store_line(map, fd);
	close(fd);
}

static void	process_size(char *line, t_map *map, int fd)
{
	int	len;

	len = (int)ft_strlen(line);
	if (len > 0 && line[len -1] == '\n')
		line[--len] = '\0';
	if (len == 0)
		return (free(line), gnl_clear(fd),
			close(fd), p_error(EMPTY_LINE));
	if (map->height == 0)
		map->width = len;
	else if (len != map->width)
		return (free(line), gnl_clear(fd),
			close(fd), p_error(NOT_RECTANGULAR));
	map->height++;
	free(line);
}

static void	load_size(int fd, t_map *map)
{
	char	*line;

	map->height = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), p_error(GNL_ERR));
	while (line)
	{
		process_size(line, map, fd);
		line = get_next_line(fd);
	}
	if (map->height < 3 || map->width < 3)
		return (close(fd), p_error(TOO_SMALL_ERR));
	else if (map->height > 16 || map->width > 30)
		return (close(fd), p_error(TOO_BIG_ERR));
}

void	map_loader(int fd, char *file, t_map *map)
{
	load_size(fd, map);
	load_map(file, map);
	close(fd);
}
