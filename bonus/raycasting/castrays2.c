/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:05:10 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/08 15:12:00 by amakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_tex(t_game *game, float y, float wall_h, float x)
{
	char	*dst;
	int		i;

	i = 0;
	if (wall_h > WIN_H)
		i = (wall_h - WIN_H) / 2;
	while (i < wall_h)
	{
		if (y >= WIN_H)
			break ;
		if (game->castrays->ra >= 180.0 && game->castrays->ra <= 360.0)
			dst = game->no_addr + (int)(i * (game->n_h / wall_h))
				% game->n_h * game->line_length[1]
				+ (int)(x * game->n_w / 64) % game->n_w
				* (game->bits_per_pixel[1] / 8);
		if (game->castrays->ra >= 0 && game->castrays->ra <= 180.0)
			dst = game->so_addr + (int)(i * (game->s_h / wall_h))
				% game->s_h * game->line_length[2]
				+ (int)(x * game->s_w / 64) % game->s_w
				* (game->bits_per_pixel[2] / 8);
		my_mlx_pixel_put(game, game->r, y, *(unsigned int *)dst);
		y++;
		i++;
	}
}

void	draw_tex2(t_game *game, float y, float lines_vert, float x)
{
	char	*dst;
	int		i;

	i = 0;
	if (lines_vert > WIN_H)
		i = (lines_vert - WIN_H) / 2;
	while (i < lines_vert)
	{
		if (y >= WIN_H)
			break ;
		if (game->castrays->ra >= 90.0 && game->castrays->ra <= 270.0)
			dst = game->we_addr + (int)(i * (game->w_h / lines_vert))
				% game->w_h * game->line_length[3]
				+ (int)(x * game->w_w / 64) % game->w_w
				* (game->bits_per_pixel[3] / 8);
		if ((game->castrays->ra >= 0 && game->castrays->ra <= 90.0)
			|| (game->castrays->ra >= 270.0 && game->castrays->ra <= 360.0))
			dst = game->ea_addr + (int)(i * (game->e_h / lines_vert))
				% game->e_h * game->line_length[4]
				+ (int)(x * game->e_w / 64) % game->e_w
				* (game->bits_per_pixel[4] / 8);
		my_mlx_pixel_put(game, game->r, y, *(unsigned int *)dst);
		y++;
		i++;
	}
}

float	fix_p_ang(float ang)
{
	if (ang < 0)
		ang += 360.0;
	if (ang > 360.0)
		ang -= 360.0;
	return (ang);
}

float	convert_d_to_r(float angle)
{
	return (angle * (PI / 180));
}
