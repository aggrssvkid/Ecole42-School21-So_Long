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

static void	return_v_on_map(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			if (mlx->map[i][j] == 'N')
			{
				mlx->map[i][j] = 'V';
			}
			j++;
		}
		i++;
	}
}

static void	what_enemy_do(t_mlx *mlx)
{
	char	obj;

	obj = mlx->map[mlx->e_move_i][mlx->e_move_j];
	if (obj == '0')
	{
		mlx->map[mlx->e_move_i][mlx->e_move_j] = 'N';
		mlx->map[mlx->e_i][mlx->e_j] = '0';
	}
	else if (obj == 'P' && mlx->evil_power > mlx->steps)
	{
		write(1, "you lost! :(\n", 13);
		exit(EXIT_SUCCESS);
	}
	else if (obj == 'P' && mlx->evil_power <= mlx->steps)
		mlx->map[mlx->e_i][mlx->e_j] = '0';
	else
		return ;
}

static void	moves(t_mlx *mlx, int nbr)
{
	if (nbr == 0)
	{
		mlx->e_move_i = mlx->e_i;
		mlx->e_move_j = mlx->e_j - 1;
	}
	else if (nbr == 1)
	{
		mlx->e_move_i = mlx->e_i + 1;
		mlx->e_move_j = mlx->e_j;
	}
	else if (nbr == 2)
	{
		mlx->e_move_i = mlx->e_i;
		mlx->e_move_j = mlx->e_j + 1;
	}
	else if (nbr == 3)
	{
		mlx->e_move_i = mlx->e_i - 1;
		mlx->e_move_j = mlx->e_j;
	}
	what_enemy_do(mlx);
	return_v_on_map(mlx);
}

void	enemy_moves(t_mlx *mlx)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			if (mlx->map[i][j] == 'V')
			{
				mlx->e_i = i;
				mlx->e_j = j;
				srand(time(NULL));
				nbr = (rand() + j) % 4;
				moves(mlx, nbr);
			}
			j++;
		}
		i++;
	}
}
