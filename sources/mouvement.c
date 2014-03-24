/*
** mouvement.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Thu Feb  6 16:44:46 2014 garcin_s
** Last update Fri Feb  7 09:47:54 2014 garcin_s
*/

#include "my.h"

void	my_up(t_game *game)
{
  if (search_select(game) == 1)
    return;
  if (game->y == 0)
    game->y = game->nbr_lines - 1;
  else
    game->y--;
  if (game->matches[game->y][game->x] == '1' ||
      game->matches[game->y][game->x] == '3')
    one_up(game);
  else if (game->matches[game->y][game->x] != '3')
    zero_up(game);
}

void	my_down(t_game *game)
{
  if (search_select(game) == 1)
    return;
  if (game->y == game->nbr_lines - 1)
    game->y = 0;
  else
    game->y++;
  if (game->matches[game->y][game->x] == '1' ||
      game->matches[game->y][game->x] == '3')
    one_down(game);
  else if (game->matches[game->y][game->x] != '3')
    zero_down(game);
}

void	my_right(t_game *game)
{
  if (game->matches[game->y][game->x + 1] == '\0')
    game->x = 0;
  else
    game->x++;
  if (game->matches[game->y][game->x] == '1' ||
      game->matches[game->y][game->x] == '3')
    one_right(game);
  else if (game->matches[game->y][game->x] != '3')
    zero_right(game);
}

void	my_left(t_game *game)
{
  if (game->x == 0)
    game->x = my_strlen(game->matches[game->y]) - 1;
  else
    game->x--;
  if (game->matches[game->y][game->x] == '3' ||
      game->matches[game->y][game->x] == '1')
    one_left(game);
  else if (game->matches[game->y][game->x] != '3')
    zero_left(game);
}
