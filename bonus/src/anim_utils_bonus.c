/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:38:55 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 12:56:06 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

long	get_ctms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

static t_pos	get_next_mob_pos(const t_game *game, t_mobs *mob)
{
	t_pos	ta_pos;
	t_pos	next_pos;
	int		dx;

	ta_pos = game->p_pos;
	next_pos = mob->pos;
	dx = mob->dir.x;
	if (mob->pos.y < ta_pos.y
		&& game->map_data->map[mob->pos.y + 1][mob->pos.x] != WALL)
		next_pos.y = mob->pos.y + 1;
	else if (mob->pos.y > ta_pos.y
		&& game->map_data->map[mob->pos.y - 1][mob->pos.x] != WALL)
		next_pos.y = mob->pos.y - 1;
	else if (game->map_data->map[mob->pos.y][mob->pos.x + dx] != WALL)
		next_pos.x = mob->pos.x + dx;
	else
		mob->dir.x *= -1;
	return (next_pos);
}

static void	handle_collision(t_game *game, t_mobs *mob, t_pos next_pos)
{
	if (next_pos.x == game->p_pos.x && next_pos.y == game->p_pos.y)
	{
		ft_printf(STARS);
		ft_printf(LOOSE_MSG);
		ft_printf(STARS);
		close_game(game);
	}
	else if (next_pos.x != mob->pos.x || next_pos.y != mob->pos.y)
	{
		mob->pos.x = next_pos.x;
		mob->pos.y = next_pos.y;
	}
}

static void	update_mobs_movement(t_game *game, long current_time)
{
	int		i;
	t_mobs	*mob;
	t_pos	next_pos;

	i = 0;
	while (i < game->mobs_nb)
	{
		mob = &game->mobs_data[i];
		if (current_time - mob->last_move_ms >= MOVE_MOBS_MS)
		{
			mob->old_pos = mob->pos;
			next_pos = get_next_mob_pos(game, mob);
			handle_collision(game, mob, next_pos);
			lite_m_render(game, mob);
			mob->last_move_ms = current_time;
		}
		i++;
	}
}

int	loop_hook(t_game *game)
{
	long	current_time;

	current_time = get_ctms();
	update_mobs_movement(game, current_time);
	return (0);
}
