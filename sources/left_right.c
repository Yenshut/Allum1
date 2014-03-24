/*
** left_right.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Fri Feb  7 09:23:49 2014 garcin_s
** Last update Fri Feb  7 09:27:21 2014 garcin_s
*/

#include "my.h"

void	zero_left(t_game *game)
{
  if (game->x == (my_strlen(game->matches[game->y]) - 1))
    game->matches[game->y][0] = '0';
  else if (game->matches[game->y][game->x + 1] == '4')
    game->matches[game->y][game->x + 1] = '1';
  else if (game->matches[game->y][game->x + 1] == '3')
    game->matches[game->y][game->x + 1] = '3';
  else
    game->matches[game->y][game->x + 1] = '0';
  game->matches[game->y][game->x] = '6';
}

void	one_left(t_game *game)
{
  if (game->matches[game->y][game->x + 1] == '4' &&
      game->matches[game->y][game->x] == '3')
    game->matches[game->y][game->x + 1] = '1';
  else if (game->matches[game->y][game->x + 1] == '4')
    game->matches[game->y][game->x + 1] = '1';
  else if (game->matches[game->y][game->x + 1] == '6')
    game->matches[game->y][game->x + 1] = '0';
  if (game->matches[game->y][game->x] == '1')
    game->matches[game->y][game->x] = '4';
  else
    game->matches[game->y][game->x] = '3';
}

void	zero_right(t_game *game)
{
  if (game->x == 0)
    game->matches[game->y][my_strlen(game->matches[game->y]) - 1] = '0';
  else if (game->matches[game->y][game->x - 1] == '4')
    game->matches[game->y][game->x - 1] = '1';
  else if (game->matches[game->y][game->x - 1] == '3')
    game->matches[game->y][game->x - 1] = '3';
  else
    game->matches[game->y][game->x - 1] = '0';
  game->matches[game->y][game->x] = '6';
}

void	one_right(t_game *game)
{
  if (game->matches[game->y][game->x - 1] == '4' &&
      game->matches[game->y][game->x] == '3')
    game->matches[game->y][game->x - 1] = '1';
  else if (game->matches[game->y][game->x - 1] == '4')
    game->matches[game->y][game->x - 1] = '1';
  else if (game->matches[game->y][game->x - 1] == '6')
    game->matches[game->y][game->x - 1] = '0';
  if (game->matches[game->y][game->x] == '1')
    game->matches[game->y][game->x] = '4';
  else
    game->matches[game->y][game->x] = '3';
}
