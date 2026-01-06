/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:07:43 by mamarti           #+#    #+#             */
/*   Updated: 2025/12/22 16:07:37 by mamarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4) || argc != 2)
		p_error(USAGE);
	init_map(argv[1], &data.map_data);
	init_data(&data.map_data, &data.game_data);
	init_game(&data.game_data);
	return (0);
}
