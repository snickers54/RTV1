/*
** my.h for my.h in /u/all/single_j/cu/rendu/lib
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Sun Oct 18 16:00:23 2009 julien singler
** Last update Thu Mar 11 02:43:23 2010 julien singler
*/

#include "mlx.h"
#include <stdarg.h>

#define BAD_OPEN_MLX		"Mlx open fail !\n"
#define BAD_VALUE		"Bad parameter's value !\n"
#define BAD_READ		"Read file failed !\n"
#define BAD_MEMORY		"Memory can't be used !\n"
#define BAD_FD			"Open file failed !\n"

typedef struct s_minilibx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*title;
  int		bpp;
  int		sizeline;
  char		*data;
  int		w_x;
  int		w_y;
} t_mini;

void	my_putchar(char c);
int	my_isneg(int n);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_revstr(char *str);  
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *str1, char *str2);
char	*my_strncat(char *str1, char *str2, int n);
int	my_strlcat(char *str1, char *str2, int n);
char	**my_str_to_wordtab(char *str);
int	my_show_to_wordtab(char **tab);
char	*my_strdup(char *str);
int	xread(int fd, char *buffer, int buff_size);
void	xmemset(char *str, int asciicode, int size);
void	free_double_tab(char **tab);
void	xopen(int fd);
void	*xmalloc(int size);

#define ERROR_BAD_TYPE			"Bad type given !\n"
#define ERROR_NO_GER			" /!\\ Option non gere /!\\ "

typedef struct	s_struct
{
  int	width;
  int	prec;
  char	sign;
  char	cara;
} t_struct;

void		print_str(va_list *arg, char c, t_struct *inf);
void		print_dec(va_list *args, int sign, t_struct *inf);
void		print_dec_unsigned(va_list *args, t_struct *inf);
void		convert_base(va_list *args, char s, int sign, t_struct *inf);
int		my_put_nbr_unsigned(unsigned int nb, t_struct *inf);
int		power(char *str);
void		norme(t_struct *inf, int k, int nb, int i);
void		help_putstr(int len, t_struct *inf, char *str);
int		spec(void);
void		print_char(va_list *args, t_struct *inf);
void		my_putchar(char c);
int		my_putstr2(char *str, t_struct *inf);
int		parser(char *str, va_list *args, int *i);
void		cond(char *str, int *i, va_list *args, t_struct *inf);
int		largeur(char *str, int *i, va_list *args, t_struct *inf);
int		prec(char *str, int *i, va_list *args, t_struct *inf);
void		last_cond(int *i, char *str, va_list *args, t_struct *inf);
void		my_printf(char *str, ...);
int		*replacement(unsigned int nbr, char *base, unsigned int *v, char *tab);
void		my_putnbr_base(unsigned int nbr, char *base, t_struct *inf);
void		put_nbr(char *tab, t_struct *inf);
int		open_minilib(t_mini *mlx, int x, int y, char *title);
