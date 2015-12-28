/*
** equation_3.c for equation_4	 in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Mar 18 10:21:26 2010 julien singler
** Last update Thu Mar 18 10:21:27 2010 julien singler
*/

#include "my_header.h"

void	resolve_troi_spe(t_solveur *so)
{
  so->nb_sol = 1;
  so->sol[0] = pow((-so->d / so->a), 1.0 / 3.0);
}

void	resolve_troi_norm(t_solveur *so)
{
  if (so->delta > 0)
    {
      so->nb_sol = 1;
      so->w = cbrt(-so->q / 2.0 + sqrt(so->delta));
      so->sol[0] = so->w - so->p / 3.0 / so->w - so->a3;
    }
  else if (so->delta == 0)
    {
      so->nb_sol = 2;
      so->sol[0] = 3 * so->q / so->p - so->a3;
      so->sol[1] = -3 * so->q / 2.0 / so->p - so->a3;
    }
  else
    {
      so->p = -so->p;
      so->nb_sol = 3;
      so->u = (2 * pow((so->p / 3.0), 0.5));
      so->v = -so->q / 2.0 / pow((so->p / 3.0), 3.0 / 2.0);
      so->t = acos(so->v) / 3.0;
      so->sol[0] = so->u * cosf(so->t) - so->a3;
      so->sol[1] = so->u * cosf(so->t + 2.0 * PI / 3.0) - so->a3;
      so->sol[2] = so->u * cosf(so->t + 4.0 * PI / 3.0) - so->a3;
    }
}

void		equation_3(t_solveur *so)
{
  if (so->a == 0)
    {
      so->a = so->b;
      so->b = so->c;
      so->c = so->d;
      equation_2(so);
    }
  else if (so->b == 0 && so->c == 0)
    resolve_troi_spe(so);
  else
    {
      so->a0 = so->d / so->a;
      so->a1 = so->c / so->a;
      so->a2 = so->b / so->a;
      so->a3 = so->a2 / 3.0;
      so->p = so->a1 - so->a3 * so->a2;
      so->q = so->a0 - so->a1 * so->a3 + 2 * pow(so->a3, 3);
      so->delta = pow(so->q / 2.0, 2) + pow(so->p / 3.0, 3);
      resolve_troi_norm(so);
    }
}
