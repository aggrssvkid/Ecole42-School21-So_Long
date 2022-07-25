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

char	**get_map(int fd, t_mlx *mlx)
{
	char	**map_here;
	char	*line;
	int		i;

	i = 0;
	map_here = malloc((mlx->win_height + 1) * sizeof (char *));
	map_here[mlx->win_height] = 0;
	while (i < mlx->win_height)
	{
		map_here[i] = malloc((mlx->win_width + 1) * sizeof (char));
		line = get_next_line(fd);
		ft_strlcpy(map_here[i], line, mlx->win_width + 1);
		i++;
		free(line);
	}
	return (map_here);
}
