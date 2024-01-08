/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:07:53 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/08 15:01:26 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player	*init_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = get_x_player(game);
	player->y = get_y_player(game);
	player->angle = 0;
	player->pdx = cos(player->angle) * 5;
	player->pdy = sin(player->angle) * 5;
	return (player);
}

t_castrays	*init_castrays(t_castrays *castrays)
{
	castrays->rx = 0;
	castrays->ry = 0;
	castrays->ra = 0;
	return (castrays);
}

void	init_game(t_game *game, char *av)
{	
	game->parse = malloc(sizeof(t_parse));
	game->map = parser(av, game->parse);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->line_length = ft_calloc(sizeof(int), 5);
	game->bits_per_pixel = ft_calloc(sizeof(int), 5);
	game->endian = ft_calloc(sizeof(int), 5);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel[0],
			&game->line_length[0], &game->endian[0]);
	game->player_size = 15;
	game->size_px_map = 64;

	game->player = init_player(game);
	game->castrays = malloc(sizeof(t_castrays));
	game->castrays = init_castrays(game->castrays);
}
