/*
** expose.c for expose in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Tue Feb  2 13:46:35 2010 julien singler
** Last update Thu Mar 18 10:57:43 2010 julien singler
*/

#include	"my_header.h"

int		gere_key(int keycode, t_glob *glob)
{
  if (keycode == ESC)
    {
      clean_list(&glob->obj);
      mlx_clear_window(glob->mlx.mlx_ptr, glob->mlx.win_ptr);
      mlx_destroy_image(glob->mlx.mlx_ptr, glob->mlx.img_ptr);
      mlx_destroy_window(glob->mlx.mlx_ptr, glob->mlx.win_ptr);
      exit(1);
    }
  return (0);
}

int		gere_expose(t_mini *mlx)
{
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
  return (0);
}
