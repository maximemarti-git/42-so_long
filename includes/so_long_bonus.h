/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:57:11 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/12 15:12:45 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <sys/time.h>
# include "text_bonus.h"
# include "../libft/includes/libft.h"

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
# else
#  include "../minilibx-opengl/mlx.h"
# endif

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLES 'C'
# define MOBS 'X'
# define VISITED '1'

# define E_SUCCESS 1
# define E_FAILURE -1

# define SPRITE_SIZE 64
# define PATH_FLOOR "assets/floor.xpm"
# define PATH_WALL "assets/wall.xpm"
# define PATH_PLAYER_R1 "assets/pacmans/pac_right1.xpm"
# define PATH_PLAYER_R2 "assets/pacmans/pac_right2.xpm"
# define PATH_PLAYER_L1 "assets/pacmans/pac_left1.xpm"
# define PATH_PLAYER_L2 "assets/pacmans/pac_left2.xpm"
# define PATH_PLAYER_D1 "assets/pacmans/pac_down1.xpm"
# define PATH_PLAYER_D2 "assets/pacmans/pac_down2.xpm"
# define PATH_PLAYER_U1 "assets/pacmans/pac_up1.xpm"
# define PATH_PLAYER_U2 "assets/pacmans/pac_up2.xpm"
# define PATH_EXIT "assets/exit/exit.xpm"
# define PATH_EXIT_PACMAN "assets/exit/exit_pacman.xpm"
# define PATH_COLLECTIBLE1 "assets/collectibles/collectibles1.xpm"
# define PATH_COLLECTIBLE2 "assets/collectibles/collectibles2.xpm"
# define PATH_COLLECTIBLE3 "assets/collectibles/collectibles3.xpm"
# define PATH_MOB1_1 "assets/mobs/mobs1_1.xpm"
# define PATH_MOB1_2 "assets/mobs/mobs1_2.xpm"
# define PATH_MOB2_1 "assets/mobs/mobs2_1.xpm"
# define PATH_MOB2_2 "assets/mobs/mobs2_2.xpm"
# define PATH_MOB3_1 "assets/mobs/mobs3_1.xpm"
# define PATH_MOB3_2 "assets/mobs/mobs3_2.xpm"
# define PATH_MOB4_1 "assets/mobs/mobs4_1.xpm"
# define PATH_MOB4_2 "assets/mobs/mobs4_2.xpm"

# ifdef __linux__
#  define KEY_ESC	65307
#  define KEY_W		119
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_UP	65362
#  define KEY_DOWN	65364
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
# else
#  define KEY_ESC	53
#  define KEY_W		13
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_UP	126
#  define KEY_DOWN	125
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
# endif

# define DESTROY_NOTIFY	17

# define FRAME_MS	1500
# define MOVE_MOBS_MS 500

typedef struct s_pos
{
	int		x;
	int		y;	
}		t_pos;

typedef struct s_map
{
	char	**map;
	char	**path_grid;
	int		height;
	int		width;
	int		collectibles;
	int		mobs;
	bool	player;
	bool	end;
	int		c_reach;
	int		m_reach;
	bool	e_reach;
	t_pos	s_pos;
	t_pos	e_pos;
}		t_map;

typedef struct s_mobs
{
	t_pos	pos;
	t_pos	old_pos;
	t_pos	dir;
	int		texture;
	int		mob_id;
	int		current_frame;
	long	last_move_ms;
}		t_mobs;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_game
{
	t_pos	p_pos;
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map_data;
	t_img	wa_img;
	t_img	fl_img;
	t_img	pl_img[4][2];
	t_img	co_img[3];
	t_img	ex_img[2];
	t_img	mo_img[4][2];
	int		moves;
	int		c_remain;
	int		mobs_nb;
	t_mobs	*mobs_data;
	int		player_direction;
	int		coll_remaining;
	int		c_cur;
	int		p_cur;
	long	last_update_ms;
}		t_game;

typedef struct s_data
{
	t_map	map_data;
	t_game	game_data;
}		t_data;

void	init_map(char *file, t_map *map);
void	init_data(t_map *map, t_game *game);
void	init_game(t_game *game);
void	map_loader(int fd, char *file, t_map *map);
void	map_checker(t_map *map);
void	path_checker(t_map *map);
void	load_textures(t_game *game);

void	free_map(t_map *map);
void	free_pathgrid(t_map *map);
void	free_textures(t_game *game);

void	handle_move(t_game *game, int kc);

void	lite_render(t_game *game, t_pos new_pos, char t_tile, int kc);
void	lite_m_render(t_game *game, t_mobs *mob);
void	render_map(t_game *game);
void	put_sprite(t_game *game, t_img *img, t_pos grid);

void	init_mobs(t_game *game);

long	get_ctms(void);
int		loop_hook(t_game *game);

void	p_error(char *str);
void	p_error_map(char *str, t_map *map);
void	p_error_double_map(char *str, t_map *map, t_map *path_grid);

void	render_counter(t_game *game);
void	render_bonus(t_game *game);

int		close_game(t_game *game);
void	close_game_error(t_game *game);

#endif