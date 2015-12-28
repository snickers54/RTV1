/*
** my_header.h for my_Header in /home/single_j/work/projet/fdf
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Dec  2 17:51:33 2009 julien singler
** Last update Wed Feb 16 19:37:33 2011 julien singler
*/

#ifndef MY_HEADER_H_
#define MY_HEADER_H_

#include "my.h"
#include "mlx.h"
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#define M_PI			3.14159265358979323846
#define TITLE			"RTV1"
#define WIDTH			1600
#define HEIGHT			1050
#define UP			65362
#define LEFT			65361
#define RIGHT			65363
#define DOWN			65364
#define ESC			65307
#define X_OEIL			-1000
#define Y_OEIL			0
#define Z_OEIL			0
#define SPEED_LINE		15
#define NO_FILE			"Open fail !\n"
#define NO_WIN			"Minilibx failed !\n"
#define NO_IMG			"IMG failed !\n"
#define NO_FD			"Can't open\n"
#define E_FILE			"Bad conf file.\n"
#define ABS(VALUE)		((VALUE) < 0 ? - (VALUE) : (VALUE))

#ifdef M_PI
# define PI M_PI
#else
# define PI 3.14159265358979323846
#endif

/* ---------------- Structures de calculs -------------------- */

typedef struct			s_position
{
  int				x;
  int				y;
  float				x1;
  float				y1;
  float				z1;
  float				vx;
  float				vy;
  float				vz;
}				t_position;

typedef struct			s_calcul
{
  float				Nx;
  float				Ny;
  float				Nz;
  float				Px;
  float				Py;
  float				Pz;
  float				k;
  int				red;
  int				blue;
  int				green;
  float				cos;
}				t_calcul;

typedef struct	s_solveur
{
  int		nb_sol;
  double	sol[4];
  double	delta;
  double	delta2;
  double	delta3;
  double	partie1;
  double	partie2;
  double	deltaprime;
  double	decal;
  double	a0;
  double	a1;
  double	a2;
  double	a3;
  double	a;
  double	aa;
  double	b;
  double	bb;
  double	c;
  double	cc;
  double	cp;
  double	d;
  double	dp;
  double	e;
  double	p;
  double	q;
  double	r;
  double	s;
  double	t;
  double	u;
  double	v;
  double	w;
  double	z;
}		t_solveur;

/* ---------------- Structures d'objets -------------------- */
typedef struct			s_objet
{
  char				*name;
  float				rayon;
  float				x;
  float				y;
  float				z;
  float				rot_x;
  float				rot_y;
  float				rot_z;
  int				red;
  int				green;
  int				blue;
  struct s_objet		*next;
  struct s_objet		*prev;
}				t_objet;

/* ---------------- Structures global -------------------- */

typedef struct			s_glob
{
  t_objet			obj;
  t_calcul			calc;
  t_position			pos;
  t_mini			mlx;
}				t_glob;


				/*--- main.c  ---*/

				/*--- calcul.c  ---*/
void				remplis_image(t_glob *glob, int x, int y);
void				position_oeil_change(t_glob *glob, t_objet *obj);
void				position_restore(t_glob *glob);
void				position_oeil_change_ombre(t_glob *glob, t_objet *spot, t_objet *obj);
void				calc_color(t_glob *glob, t_objet *obj);

				/*--- get_conf.c  ---*/
t_objet				*calc(t_glob *glob, int x, int y);
void				get_file(char *name, t_glob *glob);
void				put_sphere(char *str, t_objet *new);

				/*--- get_conf2.c  ---*/
void				put_sphere2(char *str, t_objet *new, int x);
int				ombre(t_glob *glob, t_objet *spot);
void				verif_dist(char *str, t_objet **obj, int x);
t_objet				*check_dist(float *k, float temp, t_objet *obj, t_glob *glob);

				/*--- objet.c  ---*/
float				plan(t_glob *glob, t_objet *obj);
float				sphere(t_glob *glob, t_objet *obj);
float				cone(t_glob *glob, t_objet *obj);
float				cylindre(t_glob *glob, t_objet *obj);

				/*--- luminosite.c  ---*/
void				calcul_color(t_glob *glob, float cos, t_objet *obj);
void				check_luminosite(t_glob *glob, t_objet *obj, float k);
float				luminosite(t_glob *glob, t_objet *spot);
void				check_normal(t_glob *glob, t_objet *obj);

				/*--- rotate.c  ---*/
void				rotate_oeil(t_glob *glob, t_objet *obj);
void				rotate_vecteur(t_glob *glob, t_objet *obj);

				/*--- get_next_line.c  ---*/
char				*get_next_line(const int fd);
char				*in_tab(int fd, char *tab2, int *count, int K);
void				check_open_file(int fd);
void				*xmalloc2(int size, char *tab, int usage);

				/*--- my_libx.c  ---*/
int				get_img(t_mini *mlx);
void				end_mlx(t_glob *glob);
int				open_minilib(t_mini *mlx, int x, int y, char *title);

				/*--- expose.c  ---*/
int				gere_key(int keycode, t_glob *glob);
int				gere_expose(t_mini *mlx);

				/*--- liste.c  ---*/
void				recup(t_objet **begin, char *str);
void				clean_list(void *p);

				/*--- tore.c  ---*/
float				tore(t_glob *glob, t_objet *obj);
float				resolve_tore(t_solveur *so);

				/*--- resolve.c  ---*/
void				equation_4(t_solveur *so);
void				equation_3(t_solveur *so);
void				equation_2(t_solveur *so);
void				equation_1(t_solveur *so);
void				precalculate(t_solveur *so);
void				calculate_first_sol(t_solveur *so);
void				calculate_second_sol(t_solveur *so);
#endif /* MY_HEADER_H_ */
