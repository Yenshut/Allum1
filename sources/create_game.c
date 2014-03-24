/*
** create_allum1.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Wed Feb  5 13:14:30 2014 garcin_s
** Last update Fri Feb 14 09:33:34 2014 garcin_s
*/

#include "my.h"
#include <stdio.h>

void	create_matches(t_game *game, int nbr_lines)
{
  int	a;
  int	b;
  int	c;
  int	d;

  a = 1;
  b = 0;
  d = 0;
  while (b < nbr_lines)
    {
      game->matches[b] = malloc(sizeof(char) * (a + ((nbr_lines + 2) * 2) + 1));
      c = 0;
      while (c < ((nbr_lines + 2) - d))
	game->matches[b][c++] = '0';
      while (c < (a + (nbr_lines + 2)- d))
	game->matches[b][c++] = '1';
      while (c < (a + ((nbr_lines + 2) * 2) - d))
	game->matches[b][c++] = '0';
      game->matches[b][c] = '\0';
      d++;
      b++;
      a += 2;
    }
}

void	create_game(t_game *game)
{
  game->matches = malloc(sizeof(char*) * (game->nbr_lines + 1));
  game->matches[game->nbr_lines] = NULL;
  create_matches(game, game->nbr_lines);
}
