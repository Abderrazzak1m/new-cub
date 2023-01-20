/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:55:54 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/20 16:54:08 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rays(t_cub3d *var)
{
  double ray_angle;
  int ray_3d;
  double x_wall;
  double y_wall;

  ray_3d = 0;
  ray_angle =  -VIEW / 2;
  while (ray_angle <  VIEW / 2)
  {
    x_wall = 0;
    y_wall = 0;
    intersection(var,var->alpha+  ray_angle,&x_wall,&y_wall);
    rindring3d(var,x_wall,y_wall,ray_3d,ray_angle);
    ray_angle += VIEW/WINDOW_WIDTH;
    ray_3d++;
  }
}

void get_image_add(t_cub3d *var)
{
  void *img;
  void *img1;
  void *img2;
  void *img3;
  int bbp, line, end, w, h;
  
  img = mlx_xpm_file_to_image(var->mlx, var->theme.no, &w, &h);
  img1 = mlx_xpm_file_to_image(var->mlx, var->theme.so, &w, &h);
  img2 = mlx_xpm_file_to_image(var->mlx,var->theme.we, &w, &h);
  img3 = mlx_xpm_file_to_image(var->mlx, var->theme.ea, &w, &h);
  var->data.adr = (unsigned int *)mlx_get_data_addr(img, &bbp, &line, &end);
  var->data.adr1 = (unsigned int *)mlx_get_data_addr(img1, &bbp, &line, &end);
  var->data.adr2 = (unsigned int *)mlx_get_data_addr(img2, &bbp, &line, &end);
  var->data.adr3 = (unsigned int *)mlx_get_data_addr(img3, &bbp, &line, &end);
  
}

void window(t_cub3d var)
{
  var.key_to_move_x = -1;
  var.key_to_move_y = -1;
  var.key_to_rot = -1;
	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d!");
  get_image_add(&var);
  ft_ln2d_w_h(&var);
  rindring_image(&var);
  mlx_hook(var.mlx_win, 2, 1L,key_event, &var);
  mlx_hook(var.mlx_win, 3, 1L, ref, &var);
  mlx_loop_hook(var.mlx, derection, &var);
  mlx_hook(var.mlx_win, 17, 1L, exit_game, &var);
	mlx_loop(var.mlx);
}