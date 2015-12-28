/*
** rev.c for liste in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Mar  3 10:59:23 2010 julien singler
** Last update Tue Mar 16 22:50:33 2010 julien singler
*/

#include	"my_header.h"

void		clean_list(void *p)
{
  t_objet	*begin;
  void		*temp;

  begin = p;
  while (begin && begin->prev)
    begin = begin->prev;
  begin = begin->next;
  while (begin != 0)
    {
      temp = begin->next;
      free(begin->name);
      free(begin);
      begin = temp;
    }
}

void		recup(t_objet **begin, char *str)
{
  t_objet	*new;

  new = malloc(sizeof(*new));
  if (*begin != 0)
    new->prev = (*begin)->prev;
  else
    new->prev = 0;
  put_sphere(str, new);
  new->next = *begin;
  if (*begin != 0)
    (*begin)->prev = new;
  *begin = new;
  return ;
}
