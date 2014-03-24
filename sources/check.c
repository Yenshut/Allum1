/*
** check.c for my_select in /home/garcin_s/rendu/PSU_2013_my_select
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Fri Jan 17 10:31:35 2014 garcin_s
** Last update Sun Feb  9 13:25:08 2014 garcin_s
*/
#include "my.h"

int	check_last(t_game *game, int a, int b)
{
  while (a < game->nbr_lines)
    {
      if (game->alum[a] > 0)
	b++;
      a++;
    }
  if (b == 2)
    {
      a = 0;
      while (a < game->nbr_lines)
	{
	  if (game->alum[a] == 1)
	    {
	      a = 0;
	      while (a < game->nbr_lines)
		if (game->alum[a++] > 1)
		  return (a);
	    }
	  a++;
	}
    }
  else if (b == 1)
    return (one_last(game, 0, 0));
  return (-1);
}

int	one_last(t_game *game, int a, int b)
{
  while (a < game->nbr_lines)
    {
      if (game->alum[a] == 1)
	return (-1);
      if (game->alum[a] > 1)
	return (-2);
      a++;
    }
}

void	aff_lines(int a)
{
  write(1, "Ligne ", 6);
  my_put_nbr(a + 1);
  write(1, ":   ", 4);
  if (a < 9)
    write(1, " ", 1);
}

void	check_term(char *term)
{
  if (term == 0)
    {
      write(1, TERM_0, 50);
      exit (-1);
    }
}

void	check_tgetent(int x)
{
  if (x < 0)
    {
      write(1, X_0, 50);
      exit (-1);
    }
  if (x == 0)
    {
      write(1, X_1, 50);
      exit (-1);
    }
}
