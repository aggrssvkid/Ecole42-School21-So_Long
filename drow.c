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

void	iter_80_100(t_mlx *mlx, int iter)
{
	if (iter >= 60 && iter < 80)
	{
		if (iter == 60)
			mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		drow_background(mlx);
		drow_walls(mlx);
		drow_collect2(mlx);
		drow_meditate4(mlx);
		drow_vortex4(mlx);
		drow_idle1(mlx);
		iter++;
	}
	else if (iter >= 80 && iter < 100)
	{
		if (iter == 80)
			mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		drow_background(mlx);
		drow_walls(mlx);
		drow_vortex5(mlx);
		drow_collect3(mlx);
		drow_meditate4(mlx);
		drow_idle2(mlx);
		iter++;
	}
}

void	iter_40_60(t_mlx *mlx, int iter)
{
	if (iter >= 20 && iter < 40)
	{
		if (iter == 40)
			mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		drow_background(mlx);
		drow_walls(mlx);
		drow_vortex3(mlx);
		drow_collect2(mlx);
		drow_meditate4(mlx);
		drow_idle2(mlx);
		iter++;
	}
	else if (iter >= 40 && iter < 60)
	{
		if (iter == 40)
			mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		drow_background(mlx);
		drow_walls(mlx);
		drow_vortex3(mlx);
		drow_collect2(mlx);
		drow_meditate4(mlx);
		drow_idle2(mlx);
		iter++;
	}
}

void	iter_20(t_mlx *mlx, int iter)
{
	if (iter == 0)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		drow_background(mlx);
		drow_walls(mlx);
		drow_meditate1(mlx);
	}
	else if (iter >= 10 && iter < 20)
	{
		if (iter == 10)
			mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		drow_background(mlx);
		drow_walls(mlx);
		drow_meditate2(mlx);
	}
	drow_idle1(mlx);
	drow_vortex1(mlx);
	drow_collect1(mlx);
}

int	drow(t_mlx *mlx)
{
	static int	iter;

	if (iter < 20)
	{
		iter_20(mlx, iter);
		iter++;
	}
	else if (iter >= 20 && iter < 60)
	{
		iter_40_60(mlx, iter);
		iter++;
	}
	else if (iter >= 60 && iter < 100)
	{
		iter_80_100(mlx, iter);
		iter++;
	}
	else
		iter = 0;
	drow_steps(mlx);
	return (0);
}
