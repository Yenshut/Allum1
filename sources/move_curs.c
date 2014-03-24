/*0
** move_curs.c for my_select in /home/garcin_s/rendu/PSU_2013_my_select
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Fri Jan 17 14:19:13 2014 garcin_s
** Last update Fri Feb 14 09:57:54 2014 garcin_s
*/

#include "my.h"

int	nbr_select(t_game *game)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (game->matches[game->y][a] != '\0')
    {
      if (game->matches[game->y][a] == '3')
	b++;
      a++;
    }
  return (b);
}

void	my_keys(t_game *game, struct termios *termios, t_term *term)
{
  check_matches(game, termios, term);
  if (game->buffer[0] == 27 && game->buffer[1] == 91 && game->buffer[2] == 65)
    my_up(game);
  if (game->buffer[0] == 27 && game->buffer[1] == 91 && game->buffer[2] == 66)
    my_down(game);
  if (game->buffer[0] == 27 && game->buffer[1] == 91 && game->buffer[2] == 67)
    my_right(game);
  if (game->buffer[0] == 27 && game->buffer[1] == 91 && game->buffer[2] == 68)
    my_left(game);
  if (game->buffer[0] == 32)
    {
      if (game->matches[game->y][game->x] == '3')
	game->matches[game->y][game->x] = '1';
      if (game->matches[game->y][game->x] == '4')
	game->matches[game->y][game->x] = '3';
    }
}
