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

static char	if_1_2(int key, t_mlx *mlx)
{
	char	obj;

	if (key == 1)
	{
		obj = mlx->map[mlx->p_i + 1][mlx->p_j];
		mlx->move_i = mlx->p_i + 1;
		mlx->move_j = mlx->p_j;
	}
	else if (key == 2)
	{
		obj = mlx->map[mlx->p_i][mlx->p_j + 1];
		mlx->move_i = mlx->p_i;
		mlx->move_j = mlx->p_j + 1;
	}
	return (obj);
}

char	get_obj(int key, t_mlx *mlx)
{
	char	obj;

	if (key == 13)
	{
		obj = mlx->map[mlx->p_i - 1][mlx->p_j];
		mlx->move_i = mlx->p_i - 1;
		mlx->move_j = mlx->p_j;
	}
	else if (key == 0)
	{
		obj = mlx->map[mlx->p_i][mlx->p_j - 1];
		mlx->move_i = mlx->p_i;
		mlx->move_j = mlx->p_j - 1;
	}
	else if (key == 1 || key == 2)
		obj = if_1_2(key, mlx);
	return (obj);
}
