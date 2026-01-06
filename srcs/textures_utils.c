/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:20:06 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 15:01:31 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_single_image(t_game *game, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &img->width,
			&img->height);
	if (!img->ptr)
	{
		ft_printf(FAILED_LOAD_PATH, path);
		close_game_error(game);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len,
			&img->endian);
}

void	free_textures(t_game *game)
{
	if (game->wa_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->wa_img.ptr);
	if (game->fl_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->fl_img.ptr);
	if (game->pl_img[0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[0].ptr);
	if (game->pl_img[1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[1].ptr);
	if (game->pl_img[2].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[2].ptr);
	if (game->pl_img[3].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[3].ptr);
	if (game->co_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->co_img.ptr);
	if (game->ex_img[0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->ex_img[0].ptr);
	if (game->ex_img[1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->ex_img[1].ptr);
}

void	load_textures(t_game *game)
{
	load_single_image(game, &game->wa_img, PATH_WALL);
	load_single_image(game, &game->fl_img, PATH_FLOOR);
	load_single_image(game, &game->pl_img[0], PATH_PLAYER_R);
	load_single_image(game, &game->pl_img[1], PATH_PLAYER_L);
	load_single_image(game, &game->pl_img[2], PATH_PLAYER_U);
	load_single_image(game, &game->pl_img[3], PATH_PLAYER_D);
	load_single_image(game, &game->ex_img[0], PATH_EXIT);
	load_single_image(game, &game->ex_img[1], PATH_EXIT_PACMAN);
	load_single_image(game, &game->co_img, PATH_COLLECTIBLE);
}
