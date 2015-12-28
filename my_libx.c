/*
** my_libx.c for lib_x.c in /home/single_j/work/TP/graph/tp_4
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Mar 10 12:48:58 2010 julien singler
** Last update Tue Mar 16 23:04:44 2010 snickers
*/

#include "my_header.h"

int		get_img(t_mini *mlx)
{
  int		endian;
  int		sizeline;
  int		bpp;

  if (open_minilib(mlx, WIDTH, HEIGHT, TITLE) < 0)
    {
      write(2, NO_WIN, sizeof(NO_WIN));
      return (0);
    }
  if ((mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)) == 0)
    {
      write(2, NO_IMG, sizeof(NO_IMG));
      return (0);
    }
  if ((mlx->data =
       mlx_get_data_addr(mlx->img_ptr, &bpp, &sizeline, &endian)) == 0)
    {
      write(2, NO_IMG, sizeof(NO_IMG));
      return (0);
    }
  mlx->bpp = bpp;
  mlx->sizeline = sizeline;
  return (1);
}

void		end_mlx(t_glob *glob)
{
  mlx_put_image_to_window(glob->mlx.mlx_ptr, glob->mlx.win_ptr,
			  glob->mlx.img_ptr, 0, 0);
  mlx_key_hook(glob->mlx.win_ptr, gere_key, glob);
  mlx_expose_hook(glob->mlx.win_ptr, gere_expose, &glob->mlx);
  mlx_loop(glob->mlx.mlx_ptr);
}

int		open_minilib(t_mini *mlx, int x, int y, char *title)
{
  if (x < 1 || y < 1)
    {
      my_putstr(BAD_VALUE);
      return (-1);
    }
  mlx->w_x = x;
  mlx->w_y = y;
  mlx->title = title;
  if ((mlx->mlx_ptr = mlx_init()) == 0)
    {
      my_putstr(BAD_OPEN_MLX);
      return (-1);
    }
  mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->w_x, mlx->w_y, mlx->title);
  return (0);
}
