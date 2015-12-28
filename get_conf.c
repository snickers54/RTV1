/*
** get_conf.c for get_conf.c in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Mar  3 11:20:30 2010 julien singler
** Last update Thu Mar 18 10:56:37 2010 julien singler
*/

#include "my_header.h"
#include "glob.h"

t_objet		*calc(t_glob *glob, int x, int y)
{
  t_objet	*obj;
  float		k;
  float		temp;
  t_objet	*maillon;
  int		i;
  t_objet	*maillon2;

  for (maillon = 0, glob->pos.x = x, glob->pos.y = y, k = 1000000,
	 obj = &glob->obj; obj; obj = obj->next)
    for (i = 0; gl_tab[i].obj != 0; i++)
      {
	position_oeil_change(glob, obj);
	if (my_strcmp(obj->name, gl_tab[i].obj) == 0 &&
	    my_strcmp(obj->name, "spot") != 0)
	  {	
	    rotate_vecteur(glob, obj);
	    rotate_oeil(glob, obj);
	    temp = gl_tab[i].fonction_inter(glob, obj);
	    if ((maillon2 = check_dist(&k, temp, obj, glob)) != 0)
	      maillon = maillon2;
	    break;
	  }
      }
  return (maillon);
}

void		verif_dist(char *str, t_objet **obj, int x)
{
  int		i;
  char		*nom;

  for (i = 0; gl_tab[i].obj != 0; i++)
    if (str[0] != 0 && my_strcmp(str, gl_tab[i].obj) == 0)
      {
	nom = my_strdup(str);
	str += x + 1;
	gl_tab[i].fonction_recup(obj, str);
	(*obj)->name = nom;
	str -= (x + 1);
	break;
      }
}

void		put_sphere(char *str, t_objet *new)
{
  int		i;
  int		x;
  char		buffer[512];

  xmemset(buffer, 0, 512);
  for (i = 0, x = 0; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->rayon = (float) my_getnbr(buffer);
  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->x = my_getnbr(buffer);
  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->y = my_getnbr(buffer);
  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->z = my_getnbr(buffer);
  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->red = my_getnbr(buffer);
  put_sphere2(str, new, x);
}


int		ombre(t_glob *glob, t_objet *spot)
{
  t_objet	*obj;
  float		k;
  float		temp;
  int		i;

  for (k = 1000000, obj = &glob->obj;
       obj; obj = obj->next)
    for (i = 0; gl_tab[i].obj != 0; i++)
      {
	position_oeil_change_ombre(glob, spot, obj);
	if (my_strcmp(obj->name, gl_tab[i].obj) == 0 &&
	    my_strcmp(obj->name, "spot") != 0 &&
	    my_strcmp(obj->name, "plan") != 0)
	  {
	    rotate_oeil(glob, obj);
	    rotate_vecteur(glob, obj);
	    temp = gl_tab[i].fonction_inter(glob, obj);
	    if (temp < k && temp > 0.0)
	      k = temp;
	  }
      }
  if (k > 0.00001 && k < 1.0)
    return (1);
  return (0);
}
