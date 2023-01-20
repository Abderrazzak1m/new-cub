/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:55:17 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/20 15:47:46 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_info(t_cub3d *var, int i, int j, char **map_2d)
{
	var->p_x = j * 50 + 25;
	var->p_y = i * 50 + 25;
	if (map_2d[i][j] == 'N')
		var->alpha = M_PI / 2;
	if (map_2d[i][j] == 'S')
		var->alpha = 1.5 * M_PI;
	if (map_2d[i][j] == 'W')
		var->alpha = M_PI;
	if (map_2d[i][j] == 'E')
		var->alpha = 0;
	map_2d[i][j] = '0';
}

void	pos_player(t_cub3d *var, char **map_2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	var->p_x = 0;
	var->p_y = 0;
	while (map_2d[i])
	{
		while (map_2d[i][j])
		{
			if (map_2d[i][j] == 'N' || map_2d[i][j] == 'S' || \
				map_2d[i][j] == 'W' || map_2d[i][j] == 'E')
			{
				set_info(var, i, j, map_2d);
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("Error\nno player\n");
	exit(0);
}
