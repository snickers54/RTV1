/*
** tore.c for tore in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Mar 17 15:42:10 2010 julien singler
** Last update Thu Mar 18 09:47:10 2010 julien singler
*/

#include "my_header.h"

float		tore(t_glob *glob, t_objet *obj)
{
  t_solveur	so;
  double        e;
  double        sum_d_sqrd;
  double        four_a_sqrd;
  double	f;

  sum_d_sqrd = (glob->pos.vx * glob->pos.vx) + (glob->pos.vy * glob->pos.vy) +
    (glob->pos.vz * glob->pos.vz);
  e = (glob->pos.x1 * glob->pos.x1) + (glob->pos.y1 * glob->pos.y1) +
    (glob->pos.z1 * glob->pos.z1) - (obj->rayon * obj->rayon) -
    (pow(obj->rayon / 2, 2));
  f = (glob->pos.x1 * glob->pos.vx) + (glob->pos.y1 * glob->pos.vy) +
    (glob->pos.z1 * glob->pos.vz);
  four_a_sqrd = 4 * pow(obj->rayon, 2);
  so.e = (e * e) - (four_a_sqrd * ((obj->rayon / 2 * obj->rayon / 2) -
				   (glob->pos.y1 * glob->pos.y1)));
  so.d = (4 * f * e) + (2 * four_a_sqrd * glob->pos.y1 * glob->pos.vy);
  so.c = (2 * sum_d_sqrd * e) + (4 * f * f) +
    (four_a_sqrd * glob->pos.vy * glob->pos.vy);
  so.b = 4 * sum_d_sqrd * f;
  so.a = sum_d_sqrd * sum_d_sqrd;
  return (resolve_tore(&so));
}

float		resolve_tore(t_solveur *so)
{
  int		i;
  double	temp;

  equation_4(so);
  if (so->nb_sol > 0)
    {
      temp = 10000000;
      for (i = 0; i < so->nb_sol; i++)
	if (temp > so->sol[i] && so->sol[i] > 0.001)
	  temp = so->sol[i];
      if (temp > 0)
	return (temp);
    }
  return (0);
}
