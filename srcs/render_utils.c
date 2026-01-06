/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:01:02 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 11:16:54 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_sprite(t_game *game, t_img *img, t_pos grid)
{
	t_pos	pixel;

	pixel.x = grid.x * SPRITE_SIZE;
	pixel.y = grid.y * SPRITE_SIZE;
	mlx_put_image_to_window(
		game->mlx_ptr,
		game->win_ptr,
		img->ptr,
		pixel.x,
		pixel.y
		);
}

static int	p_render(int kc)
{
	if (kc == KEY_RIGHT || kc == KEY_D)
		return (0);
	else if (kc == KEY_LEFT || kc == KEY_A)
		return (1);
	else if (kc == KEY_UP || kc == KEY_W)
		return (2);
	else if (kc == KEY_DOWN || kc == KEY_S)
		return (3);
	return (-1);
}

void	lite_render(t_game *game, t_pos next_pos, char t_tile, int kc)
{
	char	player_tile;

	player_tile = game->map_data->map[game->p_pos.y][game->p_pos.x];
	if (player_tile == EXIT)
		put_sprite(game, &game->ex_img[0], game->p_pos);
	else
		put_sprite(game, &game->fl_img, game->p_pos);
	if (t_tile == COLLECTIBLES)
		put_sprite(game, &game->fl_img, next_pos);
	if (t_tile == EXIT)
		put_sprite(game, &game->ex_img[1], next_pos);
	else
		put_sprite(game, &game->pl_img[p_render(kc)], next_pos);
}

void	render_map(t_game *game)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < game->map_data->height)
	{
		pos.x = 0;
		while (pos.x < game->map_data->width)
		{
			if (game->map_data->map[pos.y][pos.x] == WALL)
				put_sprite(game, &game->wa_img, pos);
			else
			{
				put_sprite(game, &game->fl_img, pos);
				if (game->map_data->map[pos.y][pos.x] == PLAYER)
					put_sprite(game, &game->pl_img[0], pos);
				else if (game->map_data->map[pos.y][pos.x] == EXIT)
					put_sprite(game, &game->ex_img[0], pos);
				else if (game->map_data->map[pos.y][pos.x] == COLLECTIBLES)
					put_sprite(game, &game->co_img, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}
