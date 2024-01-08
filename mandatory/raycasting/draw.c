/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:58:37 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/02 15:18:00 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIN_W || y <= 0 || y >= WIN_H)
		return ;
	dst = data->addr + (y * data->line_length[0]
			+ x * (data->bits_per_pixel[0] / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor(t_game *game, float wall_h, float lines_vert)
{
	int	i;

	i = (int)(wall_h + lines_vert);
	while (i < WIN_H)
	{
		my_mlx_pixel_put(game, game->r, i, game->parse->f_rgb);
		i++;
	}
}

void	draw_ceilling(t_game *game, float lines_vert)
{
	int	i;

	i = 0;
	while (i < lines_vert)
	{
		my_mlx_pixel_put(game, game->r, i, game->parse->c_rgb);
		i++;
	}
}

float	calcul_dist(float ax, float ay, float bx, float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}
