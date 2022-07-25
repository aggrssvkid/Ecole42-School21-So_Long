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

#ifndef LIBSOLONG_H
# define LIBSOLONG_H
# define TITLE 50
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <time.h>

typedef struct s_img
{
	int		img_width;
	int		img_height;
	void	*background;
	void	*wall;
	void	*collect;
	void	*vortex1;
	void	*vortex2;
	void	*vortex3;
	void	*vortex4;
	void	*vortex5;
	void	*collect1;
	void	*collect2;
	void	*collect3;
	void	*meditate1;
	void	*meditate2;
	void	*meditate3;
	void	*meditate4;
	void	*meditate5;
	void	*idle1;
	void	*idle2;
}	t_img;

typedef struct s_mlx
{
	int		win_width;
	int		win_height;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	int		p_i;
	int		p_j;
	int		e_i;
	int		e_j;
	int		e_move_i;
	int		e_move_j;
	int		move_i;
	int		move_j;
	int		steps;
	int		collects;
	int		evil_power;
	char	*steps_str;
	t_img	*art;
}	t_mlx;

typedef struct s_valid
{
	int		exit;
	int		collect;
	int		playerst;
	int		len;
	int		ok;
	char	*save;
}	t_valid;

int		is_valid_map(int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		is_valid_map(int fd);
void	get_params(int fd, t_mlx *mlx);
int		check_input(char **argv);
char	**get_map(int fd, t_mlx *mlx);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	startuem(t_mlx *mlx);
void	drow_background(t_mlx *mlx);
void	drow_walls(t_mlx *mlx);
void	drow_vortex1(t_mlx *mlx);
void	drow_vortex2(t_mlx *mlx);
void	drow_vortex3(t_mlx *mlx);
void	drow_vortex4(t_mlx *mlx);
void	drow_vortex5(t_mlx *mlx);
void	drow_collect1(t_mlx *mlx);
void	drow_collect2(t_mlx *mlx);
void	drow_collect3(t_mlx *mlx);
void	drow_meditate1(t_mlx *mlx);
void	drow_meditate2(t_mlx *mlx);
void	drow_meditate3(t_mlx *mlx);
void	drow_meditate4(t_mlx *mlx);
void	drow_meditate5(t_mlx *mlx);
void	drow_idle1(t_mlx *mlx);
void	drow_idle2(t_mlx *mlx);
int		drow(t_mlx *mlx);
char	get_obj(int key, t_mlx *mlx);
void	find_player(t_mlx *mlx);
int		find_collects(t_mlx *mlx);
void	what_to_do(int key, t_mlx *mlx);
void	drow_steps(t_mlx *mlx);
void	enemy_moves(t_mlx *mlx);
int		check_other_help(int fd, char *line, t_valid xd);

#endif