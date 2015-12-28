/*
** objet.c for objet in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Fri Mar 12 15:13:36 2010 julien singler
** Last update Tue Mar 16 20:10:31 2010 julien singler
*/

#include "my_header.h"

float		plan(t_glob *glob, t_objet *obj)
{
  float		k;

  if (glob->pos.vz == 0)
    return (0);
  k = - (glob->pos.z1 / glob->pos.vz);
  if (k <= 0.00001)
    return (0);
  return (k);
}

float		sphere(t_glob *glob, t_objet *obj)
{
  float		k;
  float		k1;
  float		a;
  float		b;
  float		c;
  float		delta;

  a = pow(glob->pos.vx, 2) + pow(glob->pos.vy, 2) +
    pow(glob->pos.vz, 2);
  b = 2 * ((glob->pos.x1 * glob->pos.vx) +
	   (glob->pos.y1 * glob->pos.vy) + (glob->pos.z1 * glob->pos.vz));
  c = pow(glob->pos.x1, 2) + pow(glob->pos.y1, 2)
    + pow(glob->pos.z1, 2) - (obj->rayon * obj->rayon);
  delta = pow(b, 2) - (4 * a * c);
  k = (-b - sqrt(delta)) / (2 * a);
  k1 = (-b + sqrt(delta)) / (2 * a);
  if (delta >= 0.0)
    {
      if (k < k1 && k > 0.0)
        glob->calc.k = k;
      else if (k > k1 && k1 > 0.0)
        glob->calc.k = k1;
      return (glob->calc.k);
    }
  return (0.0);
}

float		cone(t_glob *glob, t_objet *obj)
{
  float		k;
  float		k1;
  float		a;
  float		b;
  float		c;
  float		delta;

  a = pow(glob->pos.vx, 2) + pow(glob->pos.vy, 2) -
    ((1 / obj->rayon) * pow(glob->pos.vz, 2));
  b = 2 * ((glob->pos.x1 * glob->pos.vx) +
	   (glob->pos.y1 * glob->pos.vy) -
	   ((1 / obj->rayon) * (glob->pos.z1 * (glob->pos.vz))));
  c = pow(glob->pos.x1, 2) + pow(glob->pos.y1, 2) -
    ((1 / obj->rayon) * pow(glob->pos.z1, 2));
  delta = pow(b, 2) - (4 * a * c);
  k = (-b - sqrt(delta)) / (2 * a);
  k1 = (-b + sqrt(delta)) / (2 * a);
  glob->calc.k = 0.0;
  if (k < k1 && k > 0.0 && delta >= 0.0)
    glob->calc.k = k;
  else if (k > k1 && k1 > 0.0 && delta >= 0.0)
    glob->calc.k = k1;
  return (glob->calc.k);
}

float		cylindre(t_glob *glob, t_objet *obj)
{
  float		k;
  float		k1;
  float		a;
  float		b;
  float		c;
  float		delta;

  a = pow(glob->pos.vx, 2) + pow(glob->pos.vy, 2);
  b = 2 * ((glob->pos.x1 * glob->pos.vx) +
	   (glob->pos.y1 * glob->pos.vy));
  c = pow(glob->pos.x1, 2) + pow(glob->pos.y1, 2)
	   - (obj->rayon * obj->rayon);
  delta = pow(b, 2) - (4 * a * c);
  k = (-b - sqrt(delta)) / (2 * a);
  k1 = (-b + sqrt(delta)) / (2 * a);
  if (delta >= 0.0)
    {
      if (k < k1 && k > 0.0)
        glob->calc.k = k;
      else if (k > k1 && k1 > 0.0)
        glob->calc.k = k1;
      return (glob->calc.k);
    }
  return (0.0);
}
