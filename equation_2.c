/*
** equation_2.c for equation_2 in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Mar 18 10:21:14 2010 julien singler
** Last update Thu Mar 18 10:21:14 2010 julien singler
*/

#include "my_header.h"

void	calculate_sec(t_solveur *so)
{
  so->delta = (so->b * so->b) - 4 * so->a * so->c;
  if (so->delta >= 0)
    {
      so->deltaprime = sqrtf(so->delta);
      so->b = -so->b;
      so->a *= 2;
      if (so->delta == 0)
	{
	  so->sol[0] = so->b / so->a;
	  so->nb_sol = 1;
	}
      else
	{
	  so->nb_sol = 2;
	  so->sol[0] = (so->b + so->deltaprime) / so->a;
	  so->sol[1] = (so->b - so->deltaprime) / so->a;
	}
    }
  else
    so->nb_sol = 0;
}

void		equation_2(t_solveur *so)
{
  if (so->a == 0)
    {
      so->a = so->b;
      so->b = so->c;
      equation_1(so);
    }
  else
    calculate_sec(so);
}
