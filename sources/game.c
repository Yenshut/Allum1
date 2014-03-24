/*
** game.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Wed Feb  5 14:08:41 2014 garcin_s
** Last update Fri Feb 14 10:05:58 2014 garcin_s
*/

#include "my.h"

int                     my_exec(int c)
{
  my_putchar(c);
  return (0);
}

void                    set_getattr(int fo, struct termios *termios)
{
  tcgetattr(fo, termios);
  termios->c_lflag &= ~(ICANON | ECHO);
  termios->c_cc[VTIME] = 0;
  termios->c_cc[VMIN] = 1;
  tcsetattr(fo, TCSADRAIN, termios);
}

char                    *my_getenv(char *term)
{
  extern char           **environ;
  int                   a;
  int                   b;
  char                  *str;

  a = 0;
  b = 0;
  while (environ[a] != NULL && term[b] != '\0')
    {
      while (environ[a][b] != term[b] &&
             term[b] != '\0' && environ[a][b] != '\0')
        {
          b = 0;
          a++;
          if (environ[a] == NULL)
            return (NULL);
        }
      if (environ[a][b] == term[b])
        b++;
    }
  if (b == 0)
    return (NULL);
  str = malloc(sizeof(char) * my_strlen(environ[a]));
  str = my_strxcpy(str, environ[a], '=');
  return (str);
}

void                    init_term(t_term *term)
{
  int                   x;

  term->term = my_getenv("TERM=");
  check_term(term->term);
  term->fo = STDIN_FILENO;
  x = tgetent(term->buff, term->term);
  check_tgetent(x);
  term->cl = tgetstr("cl", &(term->buff));
  term->ue = tgetstr("ue", &(term->buff));
  term->so = tgetstr("so", &(term->buff));
  term->me = tgetstr("me", &(term->buff));
  term->us = tgetstr("us", &(term->buff));
  term->vi = tgetstr("vi", &(term->buff));
  term->ve = tgetstr("ve", &(term->buff));
}

void			my_game(t_game *game)
{
  struct termios	termios;
  t_term		*term;

  game->x = 0;
  game->y = 0;
  term = malloc(sizeof(*term));
  init_term(term);
  set_getattr(term->fo, &termios);
  my_refresh(game, term);
  while ((game->fileread = read(0, game->buffer, 6)))
    {
      if (game->player1 == 1)
	my_keys(game, &termios, term);
      else if (game->player2 == 1)
	my_keys(game, &termios, term);
      if (game->buffer[0] == 10)
        my_enter(game);
      if (game->buffer[0] == 27 && game->fileread == 1)
        my_esc(term, &termios);
      my_refresh(game, term);
    }
  termios.c_lflag |= (ICANON | ECHO);
  tcsetattr(term->fo, TCSADRAIN, &termios);
}
