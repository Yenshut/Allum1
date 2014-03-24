/*
** main.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Thu Jan 30 15:24:27 2014 garcin_s
** Last update Fri Feb 14 10:09:47 2014 garcin_s
*/

#include "my.h"

int		start(t_game *game)
{
  int		a;
  char		b;

  b = 0;
  while (b != 'n' && b != 'y')
    {
      write(1, B_A, my_strlen(B_A));
      game->fileread = read(0, game->buffer, 512);
      game->buffer[game->fileread] = '\0';
      b = game->buffer[0];
    }
  game->nbr_lines = 0;
  while (game->nbr_lines < 4 || game->nbr_lines > 50)
    {
      write(1, NB_L, my_strlen(NB_L));
      game->fileread = read(0, game->buffer, 512);
      game->buffer[game->fileread] = '\0';
      game->nbr_lines = my_getnbr(game->buffer);
      a = 0;
    }
  if (b == 121)
    return (0);
  else if (b == 110)
    return (1);
  return (-1);
}

void		write_matches(t_term *term, char **matches, int a, int b)
{
  if (matches[a][b] == '3')
    {
      tputs(term->so, 1, my_exec);
      write(1, "|", 1);
      tputs(term->me, 1, my_exec);
    }
  if (matches[a][b] == '6')
    {
      tputs(term->us, 1, my_exec);
      write(1, " ", 1);
      tputs(term->ue, 1, my_exec);
    }
  if (matches[a][b] == '4')
    {
      tputs(term->us, 1, my_exec);
      write(1, "|", 1);
      tputs(term->ue, 1, my_exec);
    }
  if (matches[a][b] == '0')
    write(1, " ", 1);
  if (matches[a][b] == '1')
    write(1, "|", 1);
}

void		show_matches(char **matches, t_term *term, t_game *game)
{
  int		a;
  int		b;

  a = 0;
  write(1, TOP, my_strlen(TOP));
  write(1, TOP2, my_strlen(TOP2));
  while (matches[a] != NULL)
    {
      b = 0;
      while (matches[a][b] != '\0')
	{
	  write_matches(term, matches, a, b);
	  b++;
	}
      write(1, "\n", 1);
      a++;
    }
  if (game->player1 == 1)
    write(1, PLY1, my_strlen(PLY1));
  else if (game->player2 == 1)
    write(1, PLY2, my_strlen(PLY2));
}

int		main()
{
  t_game	game;
  int		a;

  write(1, WELCOME, my_strlen(WELCOME));
  game.player1 = 1;
  game.player2 = 0;
  while (42)
    {
      if ((a = start(&game)) == 1)
	{
	  create_game(&game);
	  my_game(&game);
	}
      else if (a == 0)
	base_game(&game);
    }
  return (0);
}
