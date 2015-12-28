/*
** get_next_line.h for get_next_line.h in /home/single_j/work/projet/get_next_line
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Fri Nov 20 09:27:12 2009 julien singler
** Last update Thu Mar 18 10:24:17 2010 julien singler
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#define BAD_FD "Open file failed !\n"
#define BAD_BUFF_O "Output Buffer incorrect !\n"
#define BAD_BUFF_R "Read Buffer incorrect !\n"
#define BAD_READ "Read file failed !\n"
#define BAD_MEMORY "Memory can't be used !\n"
#define BUFF_OUTPUT 2000
#define BUFF_READ 2000

typedef struct s_truct
{
  int		i;
  char		buffer[BUFF_READ + 1];
  int		count;
} t_truc;

typedef struct s_get
{
  int		count;
  char		*tab;
  int		K;
} t_next;

char		*get_next_line(const int fd);
void		check_open_file(int fd);
void		*xmalloc2(int size, char *tab, int usage);
char		*in_tab(int fd, char *tab2, int *count, int K);

#endif /* GET_NEXT_LINE_H_ */
