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

int	check_ll(char *line, t_valid xd)
{
	char	*run;

	run = line;
	if (xd.len == (int) ft_strlen(line))
	{
		while (*run == '1')
			run++;
		if (*run == '\n' && *(run + 1) == '\0')
			return (1);
	}
	else if (xd.len - 1 == (int) ft_strlen(line))
	{
		while (*run == '1')
			run++;
		if (*run == '\0')
			return (1);
	}
	return (0);
}

int	is_line_valid(char *line, t_valid *xd)
{
	if (line == 0)
		return (0);
	if (ft_strlen(line) != xd->len)
		return (0);
	if (*line != '1' || line[(xd->len) - 2] != '1')
		return (0);
	while (*line == '1' || *line == '0' || *line == 'E' || *line == 'C' \
	|| *line == 'P' || *line == 'V')
	{
		if (*line == 'P')
			xd->playerst++;
		else if (*line == 'E')
			xd->exit = 1;
		else if (*line == 'C')
			xd->collect = 1;
		line++;
	}
	if (*line != '\n')
		return (0);
	return (1);
}

int	check_other(int fd, t_valid	xd)
{
	char	*line;
	int		check;

	xd.exit = 0;
	xd.collect = 0;
	xd.playerst = 0;
	xd.ok = 1;
	while (xd.ok == 1)
	{
		xd.save = line;
		line = get_next_line(fd);
		xd.ok = is_line_valid(line, &xd);
		if (line != 0 && *line != '\n' && xd.ok == 1)
			free(xd.save);
	}
	if (check_other_help(fd, line, xd) == 0)
		return (0);
	return (1);
}

int	is_valid_map(int fd)
{
	char	*line;
	char	*tmp;
	t_valid	xd;

	line = get_next_line(fd);
	if (line == 0)
		return (0);
	tmp = line;
	while (*tmp == '1')
		tmp++;
	if (*tmp != '\n')
	{
		free(line);
		return (0);
	}
	xd.len = (int) ft_strlen(line);
	free(line);
	if (check_other(fd, xd) == 0)
		return (0);
	return (1);
}
