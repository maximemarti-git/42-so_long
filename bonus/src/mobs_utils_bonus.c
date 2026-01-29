/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:05:42 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 12:21:30 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_mobs(t_game *game)
{
	int		i;
	t_pos	pos;

	i = 0;
	pos.y = 0;
	while (pos.y < game->map_data->height)
	{
		pos.x = 0;
		while (pos.x < game->map_data->width)
		{
			if (game->map_data->map[pos.y][pos.x] == MOBS)
			{
				game->mobs_data[i].pos = pos;
				game->mobs_data[i].old_pos = pos;
				game->mobs_data[i].dir = (t_pos){1, 0};
				game->mobs_data[i].last_move_ms = get_ctms() - (i * FRAME_MS);
				game->map_data->map[pos.y][pos.x] = FLOOR;
				game->mobs_data[i].mob_id = i % 4;
				game->mobs_data[i].current_frame = 0;
				i++;
			}
			pos.x++;
		}
		pos.y++;
	}
}
