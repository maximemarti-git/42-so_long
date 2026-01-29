/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:05:09 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 13:03:58 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	update_state(t_game *game, t_pos next_pos, int kc)
{
	char	target_tile;

	target_tile = game->map_data->map[next_pos.y][next_pos.x];
	if (target_tile == COLLECTIBLES)
	{
		game->c_remain--;
		game->map_data->map[next_pos.y][next_pos.x] = FLOOR;
	}
	if (target_tile != EXIT)
		game->map_data->map[next_pos.y][next_pos.x] = PLAYER;
	if (game->map_data->map[game->p_pos.y][game->p_pos.x] != EXIT)
		game->map_data->map[game->p_pos.y][game->p_pos.x] = FLOOR;
	lite_render(game, next_pos, target_tile, kc);
	game->p_pos = next_pos;
	game->moves++;
	render_counter(game);
}

static void	update_position(t_game *game, t_pos *next_pos, int kc)
{
	*next_pos = game->p_pos;
	if (kc == KEY_W || kc == KEY_UP)
		next_pos->y -= 1;
	else if (kc == KEY_S || kc == KEY_DOWN)
		next_pos->y += 1;
	else if (kc == KEY_A || kc == KEY_LEFT)
		next_pos->x -= 1;
	else if (kc == KEY_D || kc == KEY_RIGHT)
		next_pos->x += 1;
}

void	handle_move(t_game *game, int kc)
{
	t_pos	next_pos;
	char	target_tile;

	update_position(game, &next_pos, kc);
	if (next_pos.x < 0 || next_pos.x > game->map_data->width
		|| next_pos.y < 0 || next_pos.y > game->map_data->height)
		return ;
	target_tile = game->map_data->map[next_pos.y][next_pos.x];
	if (target_tile == WALL)
		return ;
	if (target_tile == 'E' && game->c_remain == 0)
	{
		update_state(game, next_pos, kc);
		ft_printf(STARS);
		ft_printf(SUCCESS_MSG, game->moves);
		ft_printf(STARS);
		close_game(game);
		return ;
	}
	update_state(game, next_pos, kc);
}
