/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:35:49 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 11:07:38 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_game(t_game *game)
{
	free_textures(game);
	free(game->mobs_data);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	#ifdef __linux__
		mlx_destroy_display(game->mlx_ptr);
	#endif
	free(game->mlx_ptr);
	free_map(game->map_data);
	exit(E_SUCCESS);
}

void	close_game_error(t_game *game)
{
	free_textures(game);
	free(game->mobs_data);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	#ifdef __linux__
		mlx_destroy_display(game->mlx_ptr);
	#endif
	free(game->mlx_ptr);
	free_map(game->map_data);
	exit(E_FAILURE);
}
