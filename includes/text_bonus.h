/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:13:32 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 13:01:08 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_BONUS_H
# define TEXT_BONUS_H

/* main_bonus.c */
# define USAGE "Usage: ./so_long [map_file.ber]"

/* map_loader_bonus.c */
# define NOT_RECTANGULAR "Map is not rectangular."
# define NOT_FOUND "File not found."
# define MAP_MAL_ERR "Malloc map height error."
# define EMPTY_LINE "Map contains empty lines."
# define GNL_ERR "GNL Error."
# define TOO_SMALL_ERR "Map too small."
# define TOO_BIG_ERR "Map too big."

/* map_checker_bonus.c */
# define MAP_TOPBOT_ERR "Map top or bottom wall missing."
# define MAP_WALL_ERR "Map side walls missing."
# define MAP_PE_ERR "Map must contain only one PLAYER and only one END."
# define MAP_CHAR_ERR "Invalid character in map."
# define MAP_LEAST_C "Map must contain at least 1 collectible (C)."
# define MAP_LEAST_X "Map must contain at least 1 mobs (X)."
# define MAP_LEAST_P "Map must contain exactly 1 starting point (P)."
# define MAP_LEAST_E "Map must contain exactly 1 ending point (E)."

/* map_path_checker_bonus.c */
# define COLL_ACC_ERR "Not all collectibles are accessible."
# define MOBS_ACC_ERR "Not all mobs are accessible."
# define EXIT_ACC_ERR "The exit position is not accessible."
# define GRID_H_MAL_ERR "Malloc path_grid height error."
# define GRID_W_CAL_ERR "Calloc path_grid widht error."

/* game_loader_bonus.c */
# define MLX_INIT_ERR "MLX init error."
# define WIN_INIT_ERR "MLX window creation error."
# define WINDOW_TITLE "PACXMAX - so_long.c"
# define MOBS_MAL_ERR "Malloc mobs error."

/* textures_utils_bonus.c */
# define FAILED_LOAD_PATH "Failed to load: %s"

/* handle_move_bonus.c */
# define STARS "* - - - - - - - - - - - - - - - - - - - - - *\n"
# define SUCCESS_MSG "- Congratulation you have won in %d moves !! -\n"
# define LOOSE_MSG "-                  GAME OVER                -\n"

/* render_bonus.c */
# define COUN_MAL_ERR "Malloc render_counter error"

#endif