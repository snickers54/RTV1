/*
** get_next_line.c for get in /home/single_j/work/projet/get_next_line
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Fri Nov 20 10:03:40 2009 julien singler
** Last update Fri Mar 12 16:04:37 2010 julien singler
*/

#include		"my_header.h"

static t_next		gnl;

char			*get_next_line(const int fd)
{
  int			i;
  char			*temp;

  if (gnl.K == 0)
    check_open_file(fd);
  if (gnl.K == 2)
    return (0);
  temp = xmalloc2((BUFF_OUTPUT + 1) * sizeof(char), temp, 1);
  if (gnl.tab[gnl.count] == '\n' && gnl.count == 0)
    gnl.count++;
  for (i = 0; gnl.tab[gnl.count] != '\n'; gnl.count++, i++)
    {
      if (gnl.tab[gnl.count] == 0)
	gnl.tab = in_tab(fd, gnl.tab, &(gnl.count), gnl.K);
      if ((gnl.tab[gnl.count] == 0 && gnl.K++) || i == BUFF_OUTPUT ||
	  gnl.tab[gnl.count] == '\n')
	{
	  temp[i] = 0;
	  return (temp);
	}
      temp[i] = gnl.tab[gnl.count];
    }
  temp[i] = 0;
  gnl.count++;
  return (temp);
}

char			*in_tab(int fd, char *tab2, int *count, int K)
{
  t_truc		s;

  if (gnl.K == 1)
    free(tab2);
  *count = 0;
  tab2 = xmalloc2((BUFF_READ + 1) * sizeof(char), tab2, 1);
  xmalloc2(BUFF_READ + 1, s.buffer, 0);
  if (read(fd, s.buffer, BUFF_READ) < 0)
    {
      my_putstr(BAD_READ);
      exit(1);
    }
  for (s.i = 0, s.count = 0; s.buffer[s.i] != '\0'; s.i++, s.count++)
    tab2[s.count] = s.buffer[s.i];
  tab2[s.count] = 0;
  if (gnl.K == 0 && s.count == 0)
    {
      free(tab2);
      gnl.K = 2;
      return (0);
    }
  else if (gnl.K == 0)
    gnl.K++;
  return (tab2);
}

void		check_open_file(int fd)
{
  if (fd < 0)
    {
      my_putstr(BAD_FD);
      exit(1);
    }
  if (BUFF_OUTPUT <= 0)
    {
      my_putstr(BAD_BUFF_O);
      exit(1);
    }
  if (BUFF_READ <= 0)
    {
      my_putstr(BAD_BUFF_R);
      exit(1);
    }
  gnl.tab = in_tab(fd, gnl.tab, &(gnl.count), gnl.K);
  return;
}

void		*xmalloc2(int size, char *tab, int usage)
{
  void		*p;

  if (usage == 1)
    {
      p = malloc(size);
      if (p == 0)
	{
	  my_putstr(BAD_MEMORY);
	  exit(1);
	}
      return (p);
    }
  while (usage != size)
    {
      tab[usage] = 0;
      usage++;
    }
  return (p);
}
