/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:24:16 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 13:00:33 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_counter(t_game *game)
{
	char	*moves_str;
	char	*prefix;
	int		x_offset;

	prefix = "Moves: ";
	moves_str = ft_itoa(game->moves);
	if (!moves_str)
	{
		ft_printf(COUN_MAL_ERR);
		close_game(game);
	}
	x_offset = 70;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x_offset, 80, 0xFF69B4,
		prefix);
	x_offset += 60;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x_offset, 80, 0xFF69B4,
		moves_str);
	free(moves_str);
}

void	lite_m_render(t_game *game, t_mobs *mob)
{
	char	tile_old_pos;

	if (mob->pos.x == mob->old_pos.x && mob->pos.y == mob->old_pos.y)
		return ;
	tile_old_pos = game->map_data->map[mob->old_pos.y][mob->old_pos.x];
	mob->current_frame = 1 - mob->current_frame;
	if (tile_old_pos == EXIT)
		put_sprite(game, &game->ex_img[0], mob->old_pos);
	else if (tile_old_pos == COLLECTIBLES)
		put_sprite(game, &game->co_img[game->c_cur++ % 3], mob->old_pos);
	else
		put_sprite(game, &game->fl_img, mob->old_pos);
	put_sprite(game, &game->mo_img[mob->mob_id][mob->current_frame], mob->pos);
}

static void	render_mobs(t_game *game)
{
	int		i;
	int		type;
	int		frame;
	t_img	*texture;

	i = 0;
	type = 0;
	frame = 0;
	while (i < game->mobs_nb)
	{
		type = game->mobs_data[i].mob_id;
		frame = game->mobs_data[i].current_frame;
		texture = &game->mo_img[type][frame];
		put_sprite(game, texture, game->mobs_data[i].pos);
		i++;
	}
}

void	render_bonus(t_game *game)
{
	render_mobs(game);
	render_counter(game);
}
