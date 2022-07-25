/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:33:17 by enoye             #+#    #+#             */
/*   Updated: 2021/11/08 22:21:54 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsolong.h"

int	get_height(int fd)
{
	char	*line;
	int		strings;

	strings = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0 || *line == '\n')
		{
			if (line != 0)
				free(line);
			return (strings);
		}
		free(line);
		strings++;
	}
	return (0);
}

int	get_width(int fd)
{
	char	*width;
	int		len;

	width = get_next_line(fd);
	len = (int) ft_strlen(width) - 1;
	free(width);
	return (len);
}

void	get_params(int fd, t_mlx *mlx)
{
	mlx->win_width = get_width(fd);
	mlx->win_height = get_height(fd);
}
