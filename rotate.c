/*
** rotate.c for rotate in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Feb 17 15:11:44 2010 julien singler
** Last update Tue Mar 16 13:24:44 2010 julien singler
*/

#include "my_header.h"

void		rotate_vecteur(t_glob *glob, t_objet *obj)
{
  float		x1;
  float		y1;
  float		z1;

  x1 = glob->pos.vx;
  y1 = glob->pos.vy;
  z1 = glob->pos.vz;
  glob->pos.vy = (cosf(obj->rot_x) * y1) + (-sinf(obj->rot_x) * z1);
  glob->pos.vz = (sinf(obj->rot_x) * y1) + (cosf(obj->rot_x) * z1);
  x1 = glob->pos.vx;
  y1 = glob->pos.vy;
  z1 = glob->pos.vz;
  glob->pos.vx = (cosf(obj->rot_y) * x1) + (sinf(obj->rot_y) * z1);
  glob->pos.vz = (x1 * -sinf(obj->rot_y)) + (z1 * cosf(obj->rot_y));
  x1 = glob->pos.vx;
  y1 = glob->pos.vy;
  z1 = glob->pos.vz;
  glob->pos.vx = cosf(obj->rot_z) * x1 + -sinf(obj->rot_z) * y1;
  glob->pos.vy = sinf(obj->rot_z) * x1 + cosf(obj->rot_z) * y1;
}

void		rotate_oeil(t_glob *glob, t_objet *obj)
{
  float		x1;
  float		y1;
  float		z1;

  x1 = glob->pos.x1;
  y1 = glob->pos.y1;
  z1 = glob->pos.z1;
  glob->pos.y1 = (cosf(obj->rot_x) * y1) + (-sinf(obj->rot_x) * z1);
  glob->pos.z1 = (sinf(obj->rot_x) * y1) + (cosf(obj->rot_x) * z1);
  x1 = glob->pos.x1;
  y1 = glob->pos.y1;
  z1 = glob->pos.z1;
  glob->pos.x1 = (cosf(obj->rot_y) * x1) + (sinf(obj->rot_y) * z1);
  glob->pos.z1 = (x1 * -sinf(obj->rot_y)) + (z1 * cosf(obj->rot_y));
  x1 = glob->pos.x1;
  y1 = glob->pos.y1;
  z1 = glob->pos.z1;
  glob->pos.x1 = cosf(obj->rot_z) * x1 + -sinf(obj->rot_z) * y1;
  glob->pos.y1 = sinf(obj->rot_z) * x1 + cosf(obj->rot_z) * y1;
}
