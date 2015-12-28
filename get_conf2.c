/*
** get_conf2.c for toto in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Tue Mar 16 20:12:39 2010 julien singler
** Last update Thu Mar 18 10:57:32 2010 julien singler
*/

#include "my_header.h"

void		put_sphere2(char *str, t_objet *new, int x)
{
  char		buffer[512];
  int		i;

  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->green = my_getnbr(buffer);
  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->blue = my_getnbr(buffer);
  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->rot_x = (my_getnbr(buffer) * M_PI) / 180;
  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->rot_y = (my_getnbr(buffer) * M_PI) / 180;
  xmemset(buffer, 0, 512);
  for (i = 0, x++; str[x] && str[x] != ' '; x++, i++)
    buffer[i] = str[x];
  new->rot_z = (my_getnbr(buffer) * M_PI) / 180;
}

void		get_file(char *name, t_glob *glob)
{
  int		fd;
  int		x;
  char		*str;
  t_objet	*obj;

  for (obj = 0, fd = open(name, O_RDONLY); (str = get_next_line(fd)); )
    {
      if (str[0] != '#')
	{
	  for (x = 0; str[x] && str[x] != ' '; x++);
	  str[x] = 0;
	  verif_dist(str, &obj, x);
	  str[x] = ' ';
	}
      xmemset(str, 0, my_strlen(str));
      free(str);
    }
  if (obj != 0)
    glob->obj = *obj;
  else
    {
      write(2, E_FILE, sizeof(E_FILE));
      exit(1);
    }
  close(fd);
}

t_objet		*check_dist(float *k, float temp, t_objet *obj, t_glob *glob)
{
  t_objet	*maillon;

  maillon = 0;
  if (temp < (*k) && temp > 0.00001)
    {
      (*k) = temp;
      maillon = obj;
      position_restore(glob);
      check_luminosite(glob, obj, (*k));
    }
  return (maillon);
}
