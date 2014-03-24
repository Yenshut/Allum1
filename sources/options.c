/*
** options.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Thu Feb  6 09:41:30 2014 garcin_s
** Last update Fri Feb  7 18:43:05 2014 garcin_s
*/

#include "my.h"

void	my_check(t_game *game)
{
  int	a;

  a = 0;
  if (game->buffer[0] == '\0')
    {
      write(1, THX, my_strlen(THX));
      exit (EXIT_SUCCESS);
    }
  while (game->buffer[a + 1] != '\0')
    {
      if (game->buffer[a] > '9' || game->buffer[a] < '0')
        start(game);
      a++;
    }
  if (game->fileread > 3 || game->nbr_lines > 999 || game->nbr_lines < 0)
    start(game);
}

void	my_esc(t_term *term, struct termios *termios)
{
  tputs(term->cl, 1, my_exec);
  tputs(term->ve, 1, my_exec);
  write(1, THX, my_strlen(THX));
  termios->c_lflag |= (ICANON | ECHO);
  tcsetattr(term->fo, TCSADRAIN, termios);
  exit (EXIT_SUCCESS);
}

int	search_select(t_game *game)
{
  int	a;

  a = 0;
  while (game->matches[game->y][a] != '\0')
    {
      if (game->matches[game->y][a] == '3')
	return (1);
      a++;
    }
  return (0);
}

void	my_enter(t_game *game)
{
  int	a;

  if (game->player1 == 1)
    game->player1 = 0;
  else
    game->player1 = 1;
  if (game->player2 == 1)
    game->player2 = 0;
  else
    game->player2 = 1;
  a = 0;
  while (game->matches[game->y][a] != '\0')
    {
      if (game->matches[game->y][a] == '3')
	game->matches[game->y][a] = '0';
      a++;
    }
}

void	my_refresh(t_game *game, t_term *term)
{
  tputs(term->cl, 1, my_exec);
  tputs(term->vi, 1, my_exec);
  show_matches(game->matches, term, game);
}
