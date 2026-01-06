/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:04:17 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 11:48:39 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		p_error(NOT_FOUND);
	map_loader(fd, file, map);
	map_checker(map);
}
