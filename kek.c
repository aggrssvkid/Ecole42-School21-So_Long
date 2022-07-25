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

#include "MinilibX/mlx.h"
#include "libsolong.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_mlx	*mlx;

	if (argc != 2)
		return (0);
	if (check_input(argv) != 0)
		write(1, "oke go!\n", 8);
	else
		return (0);
	mlx = malloc(sizeof(t_mlx));
	fd = open(argv[1], O_RDONLY);
	get_params(fd, mlx);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	mlx->map = get_map(fd, mlx);
	close(fd);
	startuem(mlx);
	return (0);
}
