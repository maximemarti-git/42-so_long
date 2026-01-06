/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:52:48 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/11 16:05:00 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	p_error(char *str)
{
	ft_printf("Error:\n%s\n", str);
	exit(E_FAILURE);
}

void	p_error_map(char *str, t_map *map)
{
	free_map(map);
	ft_printf("Error:\n%s\n", str);
	exit(E_FAILURE);
}

void	p_error_double_map(char *str, t_map *map, t_map *path_grid)
{
	free_map(map);
	free_pathgrid(path_grid);
	ft_printf("Error:\n%s\n", str);
	exit(E_FAILURE);
}
