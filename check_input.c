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

static int	check_file(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "nelzya read :(\n", 15);
		close(fd);
		return (0);
	}
	close (fd);
	fd = open(argv[1], O_DIRECTORY);
	if (fd > 0)
	{
		write(1, "eto papka!\n", 11);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static int	check_name(char **argv)
{
	char	*access;

	access = argv[1];
	while (*access != '.' && *access != '\0')
		access++;
	if (*access == '\0')
	{
		write(1, "nevernoe imya u file\n", 21);
		return (0);
	}
	else
	{
		if (*(access + 1) == 'b' && *(access + 2) == 'e' && \
		*(access + 3) == 'r' && *(access + 4) == '\0')
			return (1);
		else
		{
			write(1, "nevernoe imya u file\n", 21);
			return (0);
		}
	}
	return (0);
}

int	check_input(char **argv)
{
	int		fd;

	if (check_file(argv) == 0)
		return (0);
	if (check_name(argv) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (is_valid_map(fd) == 0)
	{
		printf("nu takuyu kartu mi ne prinimaem :(\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
