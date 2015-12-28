/*
** calcul.c for calcul in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Mar 10 12:57:47 2010 julien singler
** Last update Thu Mar 18 09:37:29 2010 julien singler
*/

#include "my_header.h"

void		remplis_image(t_glob *glob, int x, int y)
{
  int		count;
  t_objet	*obj;

  obj = calc(glob, x, y);
  if (obj != 0)
    {
      calc_color(glob, obj);
      count = (glob->mlx.sizeline * y) + (x * 4);
      glob->mlx.data[count] =
	mlx_get_color_value(glob->mlx.mlx_ptr, glob->calc.blue);
      glob->mlx.data[count + 1] =
	mlx_get_color_value(glob->mlx.mlx_ptr, glob->calc.green);
      glob->mlx.data[count + 2] =
	mlx_get_color_value(glob->mlx.mlx_ptr, glob->calc.red);
    }
  if (x == 0 && y % SPEED_LINE == 0)
    mlx_put_image_to_window(glob->mlx.mlx_ptr, glob->mlx.win_ptr,
			    glob->mlx.img_ptr, 0, 0);
  return ;
}

void		calc_color(t_glob *glob, t_objet *obj)
{
  float		cos;
  t_objet	*spot;
  int		i;

  i = 0;
  for (glob->calc.blue = 0, glob->calc.red = 0, glob->calc.green = 0,
	 cos = 1, spot = &glob->obj; spot; spot = spot->next)
    if (my_strcmp(spot->name, "spot") == 0)
      {
	cos = luminosite(glob, spot);
	glob->calc.blue += obj->blue * cos;
	glob->calc.red += obj->red * cos;
	glob->calc.green += obj->green * cos;
	if (ombre(glob, spot) == 1)
	  i += 30;
      }
  glob->calc.blue -= i;
  glob->calc.green -= i;
  glob->calc.red -= i;
  calcul_color(glob, cos, obj);
}

void		position_oeil_change(t_glob *glob, t_objet *obj)
{
  glob->pos.vx = WIDTH;
  glob->pos.vy = (float) (WIDTH / 2) - glob->pos.x;
  glob->pos.vz = (float) (HEIGHT / 2) - glob->pos.y;
  glob->pos.x1 = X_OEIL + obj->x;
  glob->pos.y1 = Y_OEIL + obj->y;
  glob->pos.z1 = Z_OEIL + obj->z;
}

void		position_oeil_change_ombre(t_glob *glob,
					   t_objet *spot, t_objet *obj)
{
  glob->pos.vx = spot->x - glob->calc.Px;
  glob->pos.vy = spot->y - glob->calc.Py;
  glob->pos.vz = spot->z - glob->calc.Pz;
  glob->pos.x1 = glob->calc.Px - (glob->pos.vx * 0.0001) + obj->x;
  glob->pos.y1 = glob->calc.Py - (glob->pos.vy * 0.0001) + obj->y;
  glob->pos.z1 = glob->calc.Pz - (glob->pos.vz * 0.0001) + obj->z;
}

void		position_restore(t_glob *glob)
{
  glob->pos.vx = WIDTH;
  glob->pos.vy = (float) (WIDTH / 2) - glob->pos.x;
  glob->pos.vz = (float) (HEIGHT / 2) - glob->pos.y;
  glob->pos.x1 = X_OEIL;
  glob->pos.y1 = Y_OEIL;
  glob->pos.z1 = Z_OEIL;
}
