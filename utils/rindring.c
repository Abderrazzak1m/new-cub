/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rindring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:57:02 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/17 22:05:54 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void rindring3d(t_cub3d *var, double x, double y,int ray_3d,double ray_angle)
{
  double des_to_wall;
  double wall_pjc;
  double wall;
  des_to_wall = des(var,x,y);
  des_to_wall = des_to_wall * cos (ray_angle);
  wall_pjc = (WINDOW_WIDTH /2) / tan((30 * M_PI) / 180) ;
  wall = (50 / des_to_wall) * wall_pjc ;
  float y3d = (WINDOW_HEIGHT / 2) - wall / 2;
  int l = wall/2 + WINDOW_HEIGHT/2;
  int n =0;
    while(n <  y3d)
  {
    //sma
    my_mlx_pixel_put(var, ray_3d, n, var->theme.ciel);
    n++;
  }
  int ii = 0;
  while(y3d <= WINDOW_HEIGHT/2 + wall/2  )
  {
    int m = 0;
    while( m < wall/50)
    {
      if(var->ray_type == 'l') 
        my_mlx_pixel_put(var, ray_3d , (int)y3d+m, *(var->data.adr + (int)(ii * 50 + fmod(y,50))));
      if(var->ray_type == 'u') 
           my_mlx_pixel_put(var, ray_3d , (int)y3d+m, *(var->data.adr2 + (int)(ii * 50 + fmod(x,50))));
      if(var->ray_type == 'r') 
          my_mlx_pixel_put(var, ray_3d , (int)y3d+m, *(var->data.adr1 + (int)(ii * 50 + fmod(y,50))));
      if(var->ray_type == 'd') 
          my_mlx_pixel_put(var, ray_3d , (int)y3d+m, *(var->data.adr3 + (int)(ii * 50 + fmod(x,50))));
      m++;
    }
        
       
    ii++;
    y3d+=  wall/50;
  }
	while(l <WINDOW_HEIGHT )
  {
    my_mlx_pixel_put(var, ray_3d, l, var->theme.floor);
    l++;
  }

}

