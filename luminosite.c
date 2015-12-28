/*
** luminosite.c for luminosite in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Fri Mar 12 15:14:52 2010 julien singler
** Last update Thu Mar 18 10:41:47 2010 julien singler
*/

#include "my_header.h"

void		check_luminosite(t_glob *glob, t_objet *obj, float k)
{
  glob->calc.Px = (k * glob->pos.vx) + glob->pos.x1 + obj->x;
  glob->calc.Py = (k * glob->pos.vy) + glob->pos.y1 + obj->y;
  glob->calc.Pz = (k * glob->pos.vz) + glob->pos.z1 + obj->z;
  glob->calc.Ny = glob->calc.Py;
  glob->calc.Nx = glob->calc.Px;
  check_normal(glob, obj);
  glob->calc.Px -= obj->x;
  glob->calc.Py -= obj->y;
  glob->calc.Pz -= obj->z;
}

void		check_normal(t_glob *glob, t_objet *obj)
{
  float		k;

  if (my_strcmp(obj->name, "sphere") == 0)
    glob->calc.Nz = glob->calc.Pz;
  else if (my_strcmp(obj->name, "cone") == 0)
    glob->calc.Nz = glob->calc.Pz * obj->rayon;
  else if (my_strcmp(obj->name, "cylindre") == 0)
    glob->calc.Nz = 0;
  else if (my_strcmp(obj->name, "plan") == 0)
    {
      glob->calc.Ny = 0;
      glob->calc.Nx = 0;
      glob->calc.Nz = 100;
    }
  else if (my_strcmp(obj->name, "tore") == 0)
    {
      k = (pow(glob->calc.Px, 2) + pow(glob->calc.Py, 2) + pow(glob->calc.Pz, 2)
	   - pow(obj->rayon, 2) - pow(obj->rayon / 2, 2));
      glob->calc.Nx = 4 * glob->calc.Px * k;
      glob->calc.Ny = 4 * glob->calc.Py * k;
      glob->calc.Nz = 4 * glob->calc.Pz * k + (8 * pow(obj->rayon / 2, 2) *
					       glob->calc.Pz);
    }
}

float		luminosite(t_glob *glob, t_objet *spot)
{
  float		lx;
  float		ly;
  float		lz;
  float		cosinus;

  lx = spot->x - glob->calc.Px;
  ly = spot->y - glob->calc.Py;
  lz = spot->z - glob->calc.Pz;
  cosinus = ((glob->calc.Nx * lx) + (glob->calc.Ny * ly) +
	     (glob->calc.Nz * lz)) /
    (sqrt(pow(glob->calc.Nx, 2) + pow(glob->calc.Ny, 2) +
	  pow(glob->calc.Nz, 2))
     * sqrt(pow(lx, 2) + pow(ly, 2) + pow(lz, 2)));
  if (cosinus < 0)
    cosinus = 0;
  return (cosinus);
}

void		calcul_color(t_glob *glob, float cos, t_objet *obj)
{
  if (glob->calc.red > 255)
    glob->calc.red = 255;
  if (glob->calc.blue > 255)
    glob->calc.blue = 255;
  if (glob->calc.green > 255)
    glob->calc.green = 255;
  if (glob->calc.red < 0)
    glob->calc.red = 0;
  if (glob->calc.blue < 0)
    glob->calc.blue = 0;
  if (glob->calc.green < 0)
    glob->calc.green = 0;
}
