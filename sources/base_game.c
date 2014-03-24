/*
** base_game.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Fri Feb  7 10:54:28 2014 garcin_s
** Last update Fri Feb 14 10:05:06 2014 garcin_s
*/

#include "my.h"

void	put_allum(t_game *game)
{
  int	a;
  int	b;

  a = 1;
  b = 0;
  game->alum = malloc(sizeof(int) * game->nbr_lines);
  while (b < game->nbr_lines)
    {
      game->alum[b] = a;
      b++;
      a += 2;
    }
}

void	aff_allum(t_game *game)
{
  int	a;
  int	b;
  int	c;

  a = 0;
  c = 0;
  while (a < game->nbr_lines)
    {
      b = 0;
      aff_lines(a);
      while (b < (game->nbr_lines - c))
	{
	  write(1, " ", 1);
	  b++;
	}
      b = 0;
      while (b < game->alum[a])
	{
	  write(1, "|", 1);
	  b++;
	}
      write(1, "\n", 1);
      c++;
      a++;
    }
}

void	my_play(t_game *game)
{
  game->x = 0;
  game->y = 0;
  game->player1 = 0;
  write(1, "\033[2J\033[1;1H", my_strlen("\033[2J\033[1;1H"));
  write(1, QUIT, my_strlen(QUIT));
  aff_allum(game);
  while (game->x < 1 || game->x > 50)
    {
      write(1, TAKE_X, my_strlen(TAKE_X));
      game->fileread = read(0, game->buffer, 512);
      game->buffer[game->fileread] = '\0';
      game->x = my_getnbr(game->buffer);
      check_exit(game);
    }
  while (game->y <= 0 || game->y > 1000)
    {
      write(1, TAKE_Y, my_strlen(TAKE_Y));
      game->fileread = read(0, game->buffer, 512);
      game->buffer[game->fileread] = '\0';
      game->y = my_getnbr(game->buffer);
      check_exit(game);
    }
  game->alum[(game->x - 1)] = game->alum[(game->x - 1)] - game->y;
  if (game->alum[(game->x - 1)] < 0)
    game->alum[(game->x - 1)] = 0;
}

int	allum_rest(t_game *game)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (a != game->nbr_lines)
    {
      if (game->alum[a] == 0)
	b++;
      a++;
    }
  if (b == game->nbr_lines)
    {
      if (game->player1 == 1)
	{
	  write(1, "Le Joueur 1 a gagné!\n", 22);
	  exit (EXIT_SUCCESS);
	}
      else
	{
	  write(1, "Le Bot a gagné!\n", 17);
	  exit (EXIT_SUCCESS);
	}
    }
}

void	base_game(t_game *game)
{
  game->player1 = 1;
  put_allum(game);
  while(42)
    {
      my_play(game);
      game->player1 = 0;
      allum_rest(game);
      my_calc(game);
      game->player1 = 1;
      allum_rest(game);
    }
}
