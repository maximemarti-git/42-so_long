/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:19:56 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 16:28:21 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int kc, t_game *game)
{
	if (kc == KEY_ESC)
		close_game(game);
	else if (kc == KEY_W || kc == KEY_S || kc == KEY_A
		|| kc == KEY_D || kc == KEY_UP || kc == KEY_DOWN
		|| kc == KEY_LEFT || kc == KEY_RIGHT)
		handle_move(game, kc);
	return (0);
}

static void	init_mlx(t_game *game)
{
	int	width;
	int	height;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		p_error_map(MLX_INIT_ERR, game->map_data);
	width = game->map_data->width * SPRITE_SIZE;
	height = game->map_data->height * SPRITE_SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, WINDOW_TITLE);
	if (!game->win_ptr)
		close_game(game);
}

void	init_data(t_map *map, t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map_data = map;
	game->c_remain = map->collectibles;
	game->p_pos = map->s_pos;
	game->moves = 0;
}

void	init_game(t_game *game)
{
	init_mlx(game);
	load_textures(game);
	mlx_key_hook(game->win_ptr, key_hook, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY, 0, close_game, game);
	render_map(game);
	mlx_loop(game->mlx_ptr);
}
