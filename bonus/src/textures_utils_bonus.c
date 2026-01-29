/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:20:06 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/11 17:44:05 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	free_pl_img(t_game *game)
{
	if (game->pl_img[0][0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[0][0].ptr);
	if (game->pl_img[0][1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[0][1].ptr);
	if (game->pl_img[1][0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[1][0].ptr);
	if (game->pl_img[1][1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[1][1].ptr);
	if (game->pl_img[2][0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[2][0].ptr);
	if (game->pl_img[2][1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[2][1].ptr);
	if (game->pl_img[3][0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[3][0].ptr);
	if (game->pl_img[3][1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->pl_img[3][1].ptr);
}

static void	free_mo_img(t_game *game)
{
	if (game->mo_img[0][0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->mo_img[0][0].ptr);
	if (game->mo_img[0][1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->mo_img[0][1].ptr);
	if (game->mo_img[1][0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->mo_img[1][0].ptr);
	if (game->mo_img[1][1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->mo_img[1][1].ptr);
	if (game->mo_img[2][0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->mo_img[2][0].ptr);
	if (game->mo_img[2][1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->mo_img[2][1].ptr);
	if (game->mo_img[3][0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->mo_img[3][0].ptr);
	if (game->mo_img[3][1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->mo_img[3][1].ptr);
}

void	free_textures(t_game *game)
{
	if (game->wa_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->wa_img.ptr);
	if (game->fl_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->fl_img.ptr);
	if (game->co_img[0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->co_img[0].ptr);
	if (game->co_img[1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->co_img[1].ptr);
	if (game->co_img[1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->co_img[2].ptr);
	if (game->ex_img[0].ptr)
		mlx_destroy_image(game->mlx_ptr, game->ex_img[0].ptr);
	if (game->ex_img[1].ptr)
		mlx_destroy_image(game->mlx_ptr, game->ex_img[1].ptr);
	free_pl_img(game);
	free_mo_img(game);
}

void	load_textures(t_game *game)
{
	load_single_image(game, &game->wa_img, PATH_WALL);
	load_single_image(game, &game->fl_img, PATH_FLOOR);
	load_single_image(game, &game->ex_img[0], PATH_EXIT);
	load_single_image(game, &game->ex_img[1], PATH_EXIT_PACMAN);
	load_single_image(game, &game->co_img[0], PATH_COLLECTIBLE1);
	load_single_image(game, &game->co_img[1], PATH_COLLECTIBLE2);
	load_single_image(game, &game->co_img[2], PATH_COLLECTIBLE3);
	load_single_image(game, &game->pl_img[0][0], PATH_PLAYER_R1);
	load_single_image(game, &game->pl_img[0][1], PATH_PLAYER_R2);
	load_single_image(game, &game->pl_img[1][0], PATH_PLAYER_L1);
	load_single_image(game, &game->pl_img[1][1], PATH_PLAYER_L2);
	load_single_image(game, &game->pl_img[2][0], PATH_PLAYER_U1);
	load_single_image(game, &game->pl_img[2][1], PATH_PLAYER_U2);
	load_single_image(game, &game->pl_img[3][0], PATH_PLAYER_D1);
	load_single_image(game, &game->pl_img[3][1], PATH_PLAYER_D2);
	load_single_image(game, &game->mo_img[0][0], PATH_MOB1_1);
	load_single_image(game, &game->mo_img[0][1], PATH_MOB1_2);
	load_single_image(game, &game->mo_img[1][0], PATH_MOB2_1);
	load_single_image(game, &game->mo_img[1][1], PATH_MOB2_2);
	load_single_image(game, &game->mo_img[2][0], PATH_MOB3_1);
	load_single_image(game, &game->mo_img[2][1], PATH_MOB3_2);
	load_single_image(game, &game->mo_img[3][0], PATH_MOB4_1);
	load_single_image(game, &game->mo_img[3][1], PATH_MOB4_2);
}
