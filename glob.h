/*
** my_header.h for my_Header in /home/single_j/work/projet/fdf
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Dec  2 17:51:33 2009 julien singler
** Last update Thu Mar 18 10:54:59 2010 julien singler
*/

#ifndef GLOB_H_
#define GLOB_H_

struct				s_tab
{
  char				*obj;
  void				(*fonction_recup)(t_objet **obj, char *str);
  float				(*fonction_inter)(t_glob *glob, t_objet *obj);
};

struct s_tab			gl_tab[] =
  {
    {"sphere", recup, sphere},
    {"cylindre", recup, cylindre},
    {"cone", recup, cone},
    {"plan", recup, plan},
    {"tore", recup, tore},
    {"spot", recup, 0},
    {0, 0, 0}
  };
#endif
