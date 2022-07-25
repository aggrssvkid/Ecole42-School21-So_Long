/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:49:21 by enoye             #+#    #+#             */
/*   Updated: 2022/01/21 11:49:25 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong.h"
#include "MinilibX/mlx.h"

void	drow_background(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, \
			mlx->mlx_win, mlx->art->background, j * TITLE, i * TITLE);
			j++;
		}
		i++;
	}
}
