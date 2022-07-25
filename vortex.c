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

void	drow_vortex5(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				mlx->art->vortex5, j * TITLE, i * TITLE);
			j++;
		}
		i++;
	}
}

void	drow_vortex4(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				mlx->art->vortex4, j * TITLE, i * TITLE);
			j++;
		}
		i++;
	}
}

void	drow_vortex3(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				mlx->art->vortex3, j * TITLE, i * TITLE);
			j++;
		}
		i++;
	}
}

void	drow_vortex2(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				mlx->art->vortex2, j * TITLE, i * TITLE);
			j++;
		}
		i++;
	}
}

void	drow_vortex1(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
				mlx->art->vortex1, j * TITLE, i * TITLE);
			j++;
		}
		i++;
	}
}
