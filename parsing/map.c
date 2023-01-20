/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:24:57 by amiski            #+#    #+#             */
/*   Updated: 2023/01/20 17:02:49 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_elment(char *s, int *check, t_theme *theme)
{
	if (!ft_strncmp(s, "NO ", 3) && path_valid(ft_substr(s, 3, \
		ft_strlen(s)), &theme->no))
		check[0] = check[0] + 1;
	else if (!ft_strncmp(s, "SO ", 3) && path_valid(ft_substr(s, 3, \
		ft_strlen(s)), &theme->so))
		check[1] = check[1] + 1;
	else if (!ft_strncmp(s, "WE ", 3) && path_valid(ft_substr(s, 3, \
		ft_strlen(s)), &theme->we))
		check[2] = check[2] + 1;
	else if (!ft_strncmp(s, "EA ", 3) && path_valid(ft_substr(s, 3, \
		ft_strlen(s)), &theme->ea))
		check[3] = check[3] + 1;
	else if (!ft_strncmp(s, "C ", 2) && check_color(ft_substr(s, 2, \
		ft_strlen(s)), &theme->ciel))
		check[4] = check[4] + 1;
	else if (!ft_strncmp(s, "F ", 2) && check_color(ft_substr(s, 2, \
		ft_strlen(s)), &theme->floor))
		check[5] = check[5] + 1;
	else if (ft_strtrim(s, " \n\t")[0] != '\0')
		return (1);
	if (check[0] && check[1] && check[2] && check[3] && check[4] && check[5])
		check[6] = 1;
	return (0);
}

int	check_map1(char **map2d, int i, int j)
{
	if (map2d[i][j] == '0')
		if (!ft_strchr("NSEW10", map2d[i][j + 1]) || \
		!ft_strchr("NSEW10", map2d[i][j - 1]) || \
		!ft_strchr("NSEW10", map2d[i + 1][j]) || \
		!ft_strchr("NSEW10", map2d[i - 1][j]))
			return (3);
	if (!ft_strchr("NSEW10 \t\n", map2d[i][j]))
		return (4);
	if (ft_strchr("NSEW", map2d[i][j]))
		return (5);
	return (0);
}

int	check_map(char **map2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strchr(map2d[0], '0') || ft_strchr(map2d[ft_ln2d(map2d) - 1], '0'))
		return (1);
	while (map2d[i])
	{
		if (!ft_strchr(" \n\t1", map2d[i][0]) || !ft_strchr(" \n\t1", \
			map2d[i][ft_strlen(map2d[i]) - 1]))
			return (2);
		while (map2d[i][j])
		{
			if (check_map1(map2d, i, j) != 0)
				return (check_map1(map2d, i, j));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	map1(t_cub3d *var, int fd, int *check, char **map1d)
{
	char	*s;

	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			return ;
		if (check[6] != 1)
		{
			if (check_elment(ft_strtrim(s, " \n\t"), &check[0], &var->theme))
				return ;
		}
		else
		{
			*map1d = ft_strjoin_free(*map1d, s);
			*map1d = ft_strjoin_free(*map1d, ">");
		}
		free(s);
	}
	return ;
}

void	map(int fd)
{
	t_cub3d	var;
	int		check[7];
	int		i;
	char	*map1d;

	i = -1;
	while (++i < 7)
		check[i] = 0;
	map1d = ft_strdup("");
	map1(&var, fd, &check[0], &map1d);
	if (check[6] != 1)
	{
		ft_putstr_fd("Error\nmap error", 2);
		return ;
	}
	var.map_2d = ft_split(ft_strtrim(map1d, "\n"), '>');
	pos_player(&var, var.map_2d);
	if (check_map(var.map_2d))
	{
		ft_putstr_fd("Error\nmap error", 2);
		return ;
	}
	window(var);
}
