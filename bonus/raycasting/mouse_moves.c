/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:43:47 by taelkhal          #+#    #+#             */
/*   Updated: 2023/12/23 01:43:47 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotateleft(t_game *game)
{
	game->player->angle -= 3;
	if (game->player->angle < 0)
		game->player->angle += 360.0;
	game->player->pdx = cos(convert_d_to_r(game->player->angle)) * 5;
	game->player->pdy = sin(convert_d_to_r(game->player->angle)) * 5;
}

void	rotateright(t_game *game)
{
	game->player->angle += 3;
	if (game->player->angle > 360.0)
		game->player->angle -= 360.0;
	game->player->pdx = cos(convert_d_to_r(game->player->angle)) * 5;
	game->player->pdy = sin(convert_d_to_r(game->player->angle)) * 5;
}

int	mouse_hook(int x, int y, t_game *game)
{
	if ((x > 0 && x < WIN_W) && (y > 0 && y < WIN_H))
	{
		if (game->mouse < x)
			rotateright(game);
		else if (game->mouse > x)
			rotateleft(game);
		game->mouse = x;
	}
	return (0);
}

void	move_left(t_game *game)
{
	float	new_angle;

	new_angle = game->player->angle - 90.0;
	if (new_angle < 0)
		new_angle += 360.0;
	if (game->map->map[(int)(game->player->y + sin(convert_d_to_r(new_angle))
			* P_SPEED) / game->size_px_map]
			[(int)(game->player->x) / game->size_px_map] == '0')
		game->player->y = game->player->y + sin(convert_d_to_r(new_angle)) * 5;
	if (game->map->map[(int)(game->player->y) / game->size_px_map]
		[(int)(game->player->x + cos(convert_d_to_r(new_angle)) * P_SPEED)
		/ game->size_px_map] == '0')
		game->player->x = game->player->x + cos(convert_d_to_r(new_angle)) * 5;
}
