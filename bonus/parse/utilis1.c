/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:46:01 by amakhrou          #+#    #+#             */
/*   Updated: 2024/01/02 14:46:35 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3D.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	error_empty_line(void)
{
	ft_putstr_fd(RED"ERROR:\n empty map line\n", 2);
	exit(0);
}

void	error_invalid(void)
{
	ft_putstr_fd(RED"ERROR:\n INVALID (TEXTURE) (F) (C)\n", 2);
	exit(0);
}
