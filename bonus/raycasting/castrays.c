/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:54:00 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/02 15:36:14 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	convert_3d(t_game *game, int check)
{
	float		lines_vert;
	float		wall_h;
	float		distance;
	float		tmp;
	float		pa;

	pa = fix_p_ang(game->player->angle - game->castrays->ra);
	distance = calcul_dist(game->player->x, game->player->y,
			game->castrays->rx, game->castrays->ry);
	distance = distance * cos(convert_d_to_r(pa));
	wall_h = (64 * WIN_H) / distance;
	tmp = wall_h;
	if (wall_h > WIN_H)
		wall_h = WIN_H;
	lines_vert = (WIN_H / 2.0) - (wall_h / 2.0);
	if (check == 1)
		draw_tex(game, lines_vert, tmp, game->castrays->rx);
	else
		draw_tex2(game, lines_vert, tmp, game->castrays->ry);
	draw_floor(game, wall_h, lines_vert);
	draw_ceilling(game, lines_vert);
}

void	casting(t_game *game, float x, float y)
{
	while (1)
	{
		if (game->map->map[(int)(game->castrays->ry + y) / 64]
			[(int)(game->castrays->rx / 64)] == '1')
		{
			convert_3d(game, 1);
			return ;
		}
		if (game->map->map[(int)(game->castrays->ry / 64)]
			[(int)(game->castrays->rx + x) / 64] == '1')
		{
			convert_3d(game, 0);
			return ;
		}
		game->castrays->ry += y / 4;
		game->castrays->rx += x / 4;
	}
}

void	castoneray(t_game *game)
{
	float	x;
	float	y;

	game->castrays->ra = fix_p_ang(game->player->angle - 30.0);
	game->r = 0;
	while (game->r < WIN_W)
	{
		game->castrays->rx = game->player->x;
		game->castrays->ry = game->player->y;
		x = cos(convert_d_to_r(game->castrays->ra));
		y = sin(convert_d_to_r(game->castrays->ra));
		casting(game, x, y);
		game->r++;
		game->castrays->ra += 60.0 / (WIN_W);
		game->castrays->ra = fix_p_ang(game->castrays->ra);
	}
}
