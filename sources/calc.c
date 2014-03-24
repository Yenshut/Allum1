/*
** calc.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Fri Feb  7 12:14:44 2014 garcin_s
** Last update Sun Feb 16 17:29:53 2014 garcin_s
*/

#include "my.h"

int	calc_addition(int a, int b)
{
  int	c;
  int	d;
  int	e;

  c = 0;
  d = 1;
  e = 0;
  while (a >= d || b >= d)
    {
      e += (a & d)^(b & d);
      c++;
      d *= 2;
    }
  return (e);
}

int	calc_min(t_game *game, int a)
{
  int	b;

  b = 0;
  while (a < game->nbr_lines)
    {
      b = calc_addition(b, game->alum[a]);
      a++;
    }
  return (b);
}

int	check_exception(t_game *game)
{
  int	a;
  int	b;
  int	c;

  a = 0;
  b = 0;
  c = 0;
  while (a < game->nbr_lines)
    {
      if (game->alum[a] > 0)
	{
	  if (game->alum[a] == 1)
	    c++;
	  else if (game->alum[a] > 1)
	    b++;
	}
      a++;
    }
  if (c == 3)
    return (0);
  else if (c == 2 && b == 1)
    return (1);
  return (-1);
}

void	my_calc_bis(t_game *game, int a, int c, int d)
{
  int	b;

  b = 0;
  while (b < game->nbr_lines)
    {
      c = calc_addition(game->alum[b], a);
      if (c <= game->alum[b])
	{
	  d = b;
	  b = game->nbr_lines;
	}
      b++;
    }
  if (check_last(game, 0, 0) > -1 || check_exception(game) == 0)
    c = 0;
  else if (check_last(game, 0, 0) == -2 || check_exception(game) == 1)
    c = 1;
  game->alum[d] = c;
}

void	my_calc(t_game *game)
{
  int	a;
  int	b;
  int	c;
  int	d;

  a = calc_min(game, 0);
  b = 0;
  c = 0;
  d = 0;
  if (a > 0)
    my_calc_bis(game, a, 0, 0);
  else
    {
      while (d < game->nbr_lines)
	{
	  if (game->alum[d] > game->alum[c])
	    c = d;
	  b = game->alum[c] - 1;
	  d++;
	}
      if (check_last(game, 0, 0) > -1)
	c = 0;
      game->alum[c] = b;
    }
}
