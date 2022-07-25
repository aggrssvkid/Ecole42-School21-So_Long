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

static int	check_ll(char *line, t_valid xd)
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

int	part2(int fd, char *line, t_valid xd)
{
	if (xd.ok == 0)
	{
		free(xd.save);
		if (line != 0)
			free(line);
		return (0);
	}
	else
	{
		if (line != 0 && *line == '\n')
		{
			free(xd.save);
			while (line != 0 && *line == '\n')
			{
				free(line);
				line = get_next_line(fd);
			}
			if (line != 0)
			{
				free(line);
				return (0);
			}
		}
	}
	return (1);
}

int	part1(int fd, char *line, t_valid xd)
{
	xd.save = get_next_line(fd);
	if (xd.save != 0)
	{
		free(line);
		free(xd.save);
		return (0);
	}
	else
	{
		xd.ok = check_ll(line, xd);
		if (xd.ok == 0)
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

int	check_other_help(int fd, char *line, t_valid xd)
{	
	if (line != 0 && *line != '\n' && ft_strlen(line) + 1 != xd.len)
	{
		free(line);
		return (0);
	}
	else if (line != 0 && *line != '\n' && ft_strlen(line) + 1 == xd.len)
	{
		if (part1(fd, line, xd) == 0)
			return (0);
	}
	else if (line == 0 || *line == '\n')
	{
		xd.ok = check_ll(xd.save, xd);
		if (part2(fd, line, xd) == 0)
			return (0);
	}
	if (xd.collect == 0 || xd.exit == 0 || xd.playerst != 1)
		return (0);
	return (1);
}
