/*
** equation_4.c for equation_4	 in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Mar 18 10:21:46 2010 julien singler
** Last update Thu Mar 18 10:22:33 2010 julien singler
*/

#include "my_header.h"

void		equation_4(t_solveur *so)
{
  if (!so->a == 0)
    {
      so->z = so->b / (2.0 * so->a);
      so->aa = so->c / so->a - 3.0 * (so->z * so->z) / 2.0;
      so->bb = so->d / so->a + pow(so->z, 3.0) - so->c * so->z / so->a;
      so->cc = so->e / so->a - 3 * pow(so->z, 4.0) / 16.0 + so->c *
	pow(so->z, 2.0)
	/ (4.0 * so->a) - so->d * so->z / (2.0 * so->a);
      so->dp = -2.0 * pow(so->aa, 3.0) / 27.0 - pow(so->bb, 2.0) +
	8.0 * so->aa * so->cc / 3.0;
      so->cp = -(pow(so->aa, 2.0) + 12.0 * so->cc) / 3.0;
      so->delta = pow(so->cp / 3.0, 3.0) + pow(so->dp / 2.0, 2.0);
      precalculate(so);
      calculate_first_sol(so);
      calculate_second_sol(so);
    }
  else
    {
      so->a = so->b;
      so->b = so->c;
      so->c = so->d;
      so->d = so->e;
      equation_3(so);
    }
}

void	precalculate(t_solveur *so)
{
  if (so->delta > 0)
    {
      so->w = cbrt(-so->dp / 2.0 + sqrt(so->delta));
      so->u = so->w - (so->cp / 3.0) / so->w;
    }
  else if (so->delta == 0)
    so->u = 3.0 * so->dp / so->cp;
  else
    so->u = 2 * sqrt(-so->cp / 3.0) *
      cos(acos(-so->dp / 2.0 / pow((-so->cp / 3.0), (3.0 / 2.0)))
	  / 3.0);
  so->t = so->aa / 3.0 + so->u;
  so->r = sqrt(so->t - so->aa);
  so->s = sqrt(pow(so->t / 2.0, 2.0) - so->cc);
  so->decal = -so->b / (4.0 * so->a);
}

void	calculate_first_sol(t_solveur *so)
{
  so->delta2 = so->r * so->r - 2.0 * so->t - 4.0 * so->s;
  so->partie1 = -so->r / 2.0;
  if (so->bb > 0)
    so->partie1 = -so->partie1;
  so->partie2 = sqrt(fabs(so->delta2)) / 2.0;
  if (so->delta2 < 0)
    so->nb_sol = 0;
  else
    {
      so->nb_sol = 2;
      so->sol[0] = so->partie1 + so->partie2 + so->decal;
      so->sol[1] = so->partie1 - so->partie2 + so->decal;
    }
}

void	calculate_second_sol(t_solveur *so)
{
  so->delta3 = so->r * so->r - 2.0 * so->t + 4.0 * so->s;
  so->partie1 = so->r / 2.0;
  if (so->bb > 0)
    so->partie1 = -so->partie1;
  so->partie2 = sqrt(fabs(so->delta3)) / 2.0;
  if (so->delta3 >= 0)
    {
      so->sol[so->nb_sol] = so->partie1 + so->partie2 + so->decal;

      so->sol[so->nb_sol + 1] = so->partie1 - so->partie2 + so->decal;
      so->nb_sol += 2;
    }
}
