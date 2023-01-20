#include "../cub3d.h"

void intersection(t_cub3d *var,double ray_angle,double *x_wall,double *y_wall)
{
  (void) ray_angle;
  (void) var;
  double x = *x_wall;
  double y = *y_wall;


    ray_angle = cor_angle(ray_angle);
    flor_x(var,&x,ray_angle);
    flor_y(var,&y,ray_angle);
    if(ft_up(ray_angle) && ft_right(ray_angle))
    {
      double vx , vy;
      double hx , hy;
      double desth,destv;
      hy = y;
      hx = ((var->p_y - y) / tan(M_PI *2 - ray_angle)) + var->p_x;
      vx = x;
      vy = var->p_y - ((x - var->p_x  )  *tan(M_PI *2 - ray_angle)) ;
      while (hx> 0 && hy> 0  &&hx < var->map_w && hy < var->map_h)
      { 
          if(var->map_2d[(int)floor(hy)/50 -1][(int)floor(hx)/50] == '1')
            break;
          hy-=50;
          hx+=50 / tan(M_PI *2 - ray_angle);
      }
      while (vx> 0 && vy> 0  &&vx < var->map_w && vy < var->map_h)
      {
          if(var->map_2d[(int)floor(vy)/50][(int)floor(vx)/50] == '1')
            break;
          vx+=50;
          vy-=50 * tan(M_PI *2 - ray_angle);
      }
      desth = des(var,hx,hy);
      destv = des(var,vx,vy);
      if(desth<destv)
      {
        var->ray_type = 'u';
        *x_wall =hx;
        *y_wall =hy;
      }
      else
      {
        var->ray_type = 'r';
        *x_wall =vx;
        *y_wall =vy;
      }
    }
      
    if(ft_up(ray_angle) && ft_left(ray_angle))
    {
      double vx , vy;
      double hx , hy;
      double desth,destv;
      hy = y;
      hx = var->p_x - ((var->p_y - y) / tan(ray_angle -M_PI ))  ;
      vx = x;
      vy = var->p_y - (( var->p_x - x)  *tan( ray_angle - M_PI  )) ;
      while (hx> 0 && hy> 0  &&hx < var->map_w && hy < var->map_h)
      { 
          if(var->map_2d[(int)floor(hy)/50 -1][(int)floor(hx)/50] == '1')
            break;
            hy -= 50;
            hx -= 50 / tan(ray_angle -M_PI );
      }
      while (vx>= 0 && vy>= 0  &&vx < var->map_w && vy < var->map_h)
      {
          if(var->map_2d[(int)floor(vy)/50][(int)floor(vx)/50 -1] == '1')
            break;
          vx-=50;
          vy-=50 * tan(ray_angle -M_PI );
      }
      desth = des(var,hx,hy);
      destv = des(var,vx,vy);
      if(desth<destv)
      {
        var->ray_type = 'u';
        *x_wall =hx;
        *y_wall =hy;
      }
      else
      {
        var->ray_type = 'l';
        *x_wall =vx;
        *y_wall =vy;
      }
    }
      
    if(ft_down(ray_angle) && ft_right(ray_angle))
    {
      double vx , vy;
      double hx , hy;
      double desth,destv;
      hy = y;
      hx =  (( y -var->p_y) / tan(ray_angle )) + var->p_x  ;
      vx = x;
      vy = var->p_y + (( x -  var->p_x)  *tan( ray_angle )) ;
      while (hx> 0 && hy>0  &&hx < var->map_w && hy < var->map_h)
      { 
          if(var->map_2d[(int)floor(hy)/50][(int)floor(hx)/50] == '1')
            break;
            hy += 50;
            hx += 50 / tan(ray_angle );
      }
      while (vx>= 0 && vy>= 0  &&vx < var->map_w && vy < var->map_h)
      {
          if(var->map_2d[(int)floor(vy)/50][(int)floor(vx)/50] == '1')
            break;
          vx+=50;
          vy+=50 * tan(ray_angle);
      }
      desth = des(var,hx,hy);
      destv = des(var,vx,vy);
      if(desth<destv)
      {
        var->ray_type = 'd';
        *x_wall =hx;
        *y_wall =hy;
      }
      else
      {
        var->ray_type = 'r';
        *x_wall =vx;
        *y_wall =vy;
      }

    }
    if(ft_down(ray_angle) && ft_left(ray_angle))
    {
      double vx , vy;
      double hx , hy;
      double desth,destv;
      hy = y;
      hx = var->p_x - (( y -var->p_y) / tan( M_PI - ray_angle ));
      vx = x;
      vy = var->p_y + ((var->p_x - x)  *tan( M_PI - ray_angle ));
      while (hx> 0 && hy> 0 && hx < var->map_w && hy < var->map_h)
      { 
          if(var->map_2d[(int)floor(hy)/50][(int)floor(hx)/50] == '1')
            break;
          hy += 50;
          hx -= 50 / tan(M_PI - ray_angle );
      }
      while (vx>= 0 && vy>= 0  &&vx < var->map_w && vy < var->map_h)
      {
          if(var->map_2d[(int)floor(vy)/50][(int)floor(vx)/50 -1] == '1')
            break;
          vx-=50;
          vy+=50 * tan(M_PI - ray_angle);
      }
      desth = des(var,hx,hy);
      destv = des(var,vx,vy);
      if(desth<destv)
      {
        var->ray_type = 'd';
        *x_wall =hx;
        *y_wall =hy;
      }
      else
      {
        var->ray_type = 'l';
        *x_wall =vx;
        *y_wall =vy;
      }

    }
}