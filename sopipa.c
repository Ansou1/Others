/*
** sopipa.c for sopipa in /home/daguen_s/
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Wed May 22 19:29:49 2013 simon daguenet
** Last update Wed May 22 19:29:57 2013 simon daguenet
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*my_strdup(char *str)
{
  int	i = 0;
  char	*ret;

  while (str[i])
    i++;
  if ((ret = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

void	exec_com(char *com)
{
  char	**tab;

  tab = malloc(sizeof (char *) * 4);
  tab[0] = my_strdup("./sopipa");
  tab[1] = my_strdup("-c");
  tab[2] = com;
  tab[3] = NULL;
  execv("/bin/bash", tab);
}

void	exec_all(char **av)
{
  int	fd;
  int	p1;
  int	p[2];

  if ((fd = open(av[1], O_RDONLY)) == -1)
    exit(0);
  pipe(p);
  p1 = fork();
  if (p1 == 0)
    {
      close(p[0]);
      dup2(p[1], 1);
      dup2(fd, 0);
      exec_com(av[2]);
      exit(0);
    }
  close(p[1]);
  dup2(p[0], 0);
  exec_com(av[3]);
}

int	main(int ac, char **av)
{
  pid_t	pid;
  int	fd_out;
  int	status;

  if (ac != 5)
    {
      printf("\n");
      return (0);
    }
  pid = fork();
  if ((fd_out = open(av[4], O_WRONLY | O_CREAT, S_IRWXU)) == -1)
    exit(0);
  if (pid == 0)
    {
      dup2(fd_out, 1);
      exec_all(av);
    }
  wait3(&status, 0, 0);
  return 0;
}
