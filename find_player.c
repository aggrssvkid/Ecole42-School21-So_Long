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

void	find_player(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->win_height)
	{
		j = 0;
		while (j < mlx->win_width)
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->p_i = i;
				mlx->p_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
