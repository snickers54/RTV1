/*
** equation_1.c for equation_1 in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Mar 18 10:21:01 2010 julien singler
** Last update Thu Mar 18 10:21:02 2010 julien singler
*/

#include "my_header.h"

void	equation_1(t_solveur *e)
{
  e->sol[0] = -e->b / e->a;
  e->nb_sol = 1;
}
