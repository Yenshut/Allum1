/*
** check2.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Sun Feb  9 13:29:47 2014 garcin_s
** Last update Sun Feb 16 16:18:03 2014 garcin_s
*/

#include "my.h"

void	check_exit(t_game *game)
{
  if (game->buffer[0] == '\0')
    {
      write(1, THX, my_strlen(THX));
      exit (EXIT_SUCCESS);
    }
}

void	exit_1(t_game *game, struct termios *termios, t_term *term)
{
  write(1, "\nJoueur 2 a gagné\nMerci d'avoir joué !\n", 41);
  tputs(term->ve, 1, my_exec);
  termios->c_lflag |= (ICANON | ECHO);
  tcsetattr(term->fo, TCSADRAIN, termios);
  exit (EXIT_SUCCESS);
}

void	exit_2(t_game *game, struct termios *termios, t_term *term)
{
  write(1, "\nJoueur 1 a gagné\nMerci d'avoir joué !\n", 41);
  tputs(term->ve, 1, my_exec);
  termios->c_lflag |= (ICANON | ECHO);
  tcsetattr(term->fo, TCSADRAIN, termios);
  exit (EXIT_SUCCESS);
}

void	check_matches(t_game *game, struct termios *termios, t_term *term)
{
  int	a;
  int	b;
  int	c;

  a = 0;
  c = 0;
  while (a != game->nbr_lines)
    {
      b = 0;
	while (game->matches[a][b] != '\0')
	  {
	    if (game->matches[a][b] == '1' || game->matches[a][b] == '3')
	      c++;
	    b++;
	  }
      a++;
    }
  if (c == 0 && game->player1 == 1)
    exit_1(game, termios, term);
  if (c == 0 && game->player2 == 1)
    exit_2(game, termios, term);
}
