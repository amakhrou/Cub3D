/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:47:03 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/02 18:13:49 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx, game->no_text);
	mlx_destroy_image(game->mlx, game->so_text);
	mlx_destroy_image(game->mlx, game->ea_text);
	mlx_destroy_image(game->mlx, game->we_text);
}

int	free_exit(t_game *game)
{
	if (game->mlx)
	{
		if (game->img)
			mlx_destroy_image(game->mlx, game->img);
		mlx_destroy_window(game->mlx, game->win);
		free_textures(game);
		free(game->mlx);
	}
	free(game);
	exit (0);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (n > 0)
	{
		str[i] = 0;
		i++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, (count * size));
	return (str);
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
