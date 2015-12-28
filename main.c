/*
** main.c for main in /home/single_j/work/projet/wolf3D
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Dec 17 09:57:59 2009 julien singler
** Last update Thu Mar 18 10:48:37 2010 julien singler
*/

#include	"my_header.h"

int		main(int ac, char **av)
{
  t_glob	glob;
  int		x;
  int		y;

  get_file(av[1], &glob);
  if (get_img(&glob.mlx) == 0)
    exit(1);
  for (y = 0; y < HEIGHT; y++)
    for (x = 0; x < WIDTH; x++)
      remplis_image(&glob, x, y);
  end_mlx(&glob);
  return (0);
}
