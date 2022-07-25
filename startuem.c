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

void	get_arts2(t_mlx *mlx)
{
	mlx->art->meditate1 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/meditate/meditate1.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->meditate2 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/meditate/meditate2.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->meditate3 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/meditate/meditate3.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->meditate4 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/meditate/meditate4.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->meditate5 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/meditate/meditate5.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->idle1 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/enemy_idle/idle1.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->idle2 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/enemy_idle/idle2.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
}

void	get_arts(t_mlx *mlx)
{
	mlx->art->background = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/background/background.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/wall/wall.xpm", &(mlx->art->img_width), &(mlx->art->img_height));
	mlx->art->vortex1 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/vortex/vortex1.xpm", &(mlx->art->img_width), &(mlx->art->img_height));
	mlx->art->vortex2 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/vortex/vortex2.xpm", &(mlx->art->img_width), &(mlx->art->img_height));
	mlx->art->vortex3 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/vortex/vortex3.xpm", &(mlx->art->img_width), &(mlx->art->img_height));
	mlx->art->vortex4 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/vortex/vortex4.xpm", &(mlx->art->img_width), &(mlx->art->img_height));
	mlx->art->vortex5 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/vortex/vortex5.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->collect1 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/collect/collect1.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->collect2 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/collect/collect2.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
	mlx->art->collect3 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"XPM/collect/collect3.xpm", &(mlx->art->img_width), \
	&(mlx->art->img_height));
}

int	wtf(int key, t_mlx *mlx)
{
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		what_to_do(key, mlx);
		enemy_moves(mlx);
	}
	else if (key == 53)
	{
		free(mlx);
		mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	startuem(t_mlx *mlx)
{
	mlx->art = malloc(sizeof(t_img));
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->win_width * TITLE, \
	mlx->win_height * TITLE, "THE RETURN OF THE KOLYAN!");
	get_arts(mlx);
	get_arts2(mlx);
	find_player(mlx);
	mlx->collects = find_collects(mlx);
	mlx->steps = 0;
	mlx->evil_power = mlx->win_height;
	mlx_loop_hook(mlx->mlx_ptr, &drow, mlx);
	mlx_key_hook(mlx->mlx_win, &wtf, mlx);
	mlx_loop(mlx->mlx_ptr);
}
