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

static void	if_c(t_mlx *mlx, char obj)
{
	if (obj == 'C')
	{
		mlx->map[mlx->p_i][mlx->p_j] = '0';
		mlx->map[mlx->move_i][mlx->move_j] = 'P';
		mlx->p_i = mlx->move_i;
		mlx->p_j = mlx->move_j;
		mlx->steps++;
		mlx->collects--;
	}
	else if (obj == 'E')
	{
		if (mlx->collects == 0)
		{
			write(1, "FLAWLESS VICTORYCH!\n", 20);
			exit(EXIT_SUCCESS);
		}
		else
			return ;
	}
}

static void	if_0_1(t_mlx *mlx, char obj)
{	
	if (obj == '0')
	{
		mlx->map[mlx->p_i][mlx->p_j] = '0';
		mlx->map[mlx->move_i][mlx->move_j] = 'P';
		mlx->p_i = mlx->move_i;
		mlx->p_j = mlx->move_j;
		mlx->steps++;
	}
	else if (obj == '1')
	{
		return ;
	}
}

void	what_to_do(int key, t_mlx *mlx)
{
	char	obj;

	obj = get_obj(key, mlx);
	if (obj == '0' || obj == '1')
		if_0_1(mlx, obj);
	else if (obj == 'C' || obj == 'E')
		if_c(mlx, obj);
	else if (obj == 'V')
	{
		if (mlx->steps >= mlx->evil_power)
		{
			mlx->map[mlx->p_i][mlx->p_j] = '0';
			mlx->map[mlx->move_i][mlx->move_j] = 'P';
			mlx->p_i = mlx->move_i;
			mlx->p_j = mlx->move_j;
			mlx->steps++;
		}
		else
		{
			write(1, "you lost! :(\n", 13);
			exit(EXIT_SUCCESS);
		}
	}
}
