/*
** up_down.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Fri Feb  7 09:18:48 2014 garcin_s
** Last update Fri Feb  7 10:12:24 2014 garcin_s
*/

#include "my.h"

void	zero_up(t_game *game)
{
  if (game->y == (game->nbr_lines - 1))
    game->matches[0][game->x] = '0';
  else if (game->matches[game->y + 1][game->x] == '4')
    game->matches[game->y + 1][game->x] = '1';
  else if (game->matches[game->y + 1][game->x] == '6')
    game->matches[game->y + 1][game->x] = '0';
  if (game->matches[game->y][game->x] == '1')
    game->matches[game->y][game->x] = '4';
  else
    game->matches[game->y][game->x] = '6';
}

void	one_up(t_game *game)
{
  if (game->y == (game->nbr_lines - 1) && game->matches[0][game->x] == '6')
    game->matches[0][game->x] = '0';
  else if (game->y == (game->nbr_lines - 1) &&
	   game->matches[0][game->x] == '4')
    game->matches[0][game->x] = '1';
  else if (game->matches[game->y + 1][game->x] == '4')
    game->matches[game->y + 1][game->x] = '1';
  else if (game->matches[game->y + 1][game->x] == '6')
    game->matches[game->y + 1][game->x] = '0';
  if (game->matches[game->y][game->x] == '1')
    game->matches[game->y][game->x] = '4';
  else
    game->matches[game->y][game->x] = '3';
}

void	one_down(t_game *game)
{
  if (game->y == 0 && game->matches[(game->nbr_lines - 1)][game->x] != '6')
    game->matches[(game->nbr_lines - 1)][game->x] = '1';
  else if (game->matches[game->y - 1][game->x] == '4')
    game->matches[game->y - 1][game->x] = '1';
  else if (game->matches[game->y - 1][game->x] == '6')
    game->matches[game->y - 1][game->x] = '0';
  if (game->matches[game->y][game->x] == '1')
    game->matches[game->y][game->x] = '4';
  else
    game->matches[game->y][game->x] = '3';
}

void	zero_down(t_game *game)
{
  if (game->y == 0 && game->matches[(game->nbr_lines - 1)][game->x] != '4')
    game->matches[(game->nbr_lines - 1)][game->x] = '0';
  else if (game->y == 0 &&
	   game->matches[(game->nbr_lines - 1)][game->x] == '4')
    game->matches[(game->nbr_lines - 1)][game->x] = '1';
  else if (game->matches[game->y - 1][game->x] == '4')
    game->matches[game->y - 1][game->x] = '1';
  else
    game->matches[game->y - 1][game->x] = '0';
  if (game->matches[game->y][game->x] == '1')
    game->matches[game->y][game->x] = '4';
  else
    game->matches[game->y][game->x] = '6';
}
