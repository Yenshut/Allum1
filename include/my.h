/*
** my.h for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Thu Jan 30 15:26:31 2014 garcin_s
** Last update Sun Feb 16 16:40:42 2014 garcin_s
*/

#ifndef _MY_H_
# define _MY_H_

/*
** ----- INCLUDES -----
*/

#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <ncurses.h>
#include <curses.h>
#include <term.h>

/*
** ----- MACROS -----
*/

#define WELCOME	"\n\t\tBienvenue sur le jeu des allumettes !\n\n\n"
#define	NB_L	"Veuillez choisir le nombre de lignes (4 à 50): "
#define TERM_0	"\033[01;31mERROR:\033[00mTerminal type is not define.\n"
#define X_0	"ERROR:Could not access the termcap data.\n"
#define X_1	"\033[01;31mERROR:\033[00mTerminal type is not correct.\n"
#define THX	"\n\t\tMerci d'avoir joué !\n\t\t   Arrêt du jeu.\n"
#define	QUIT	"Appuiez sur CTRL + D pour quitter\n\n"
#define B_A	"Voulez-vous jouer contre un bot ? (yes - no): "
#define TAKE_X	"\nQuelle ligne choisissez-vous ?: "
#define TAKE_Y	"\nCombien en choisissez-vous ?: "
#define TOP	"\033[01;31mQuitter = 'echap\nBouger = 'flèches'\n"
#define	TOP2	"Séléctionner = 'espace'\nEnlever = 'Entrée'\n\n\033[00m"
#define	PLY1	"C'est au tour du Joueur 1."
#define	PLY2	"C'est au tour du Joueur 2."

/*
** ----- STRUCTURES -----
*/

typedef	struct	s_game
{
  int		nbr_lines;
  int		fileread;
  int		x;
  int		y;
  char		player1;
  char		player2;
  int		*alum;
  char		prev;
  char		**matches;
  char		buffer[512];
}		t_game;

typedef struct	s_term
{
  int		fo;
  char		*term;
  char		*buff;
  char		*cl;
  char		*so;
  char		*me;
  char		*ue;
  char		*us;
  char		*ve;
  char		*vi;
}		t_term;

/*
** ----- PROTOTYPES -----
*/

void	my_up(t_game *game);
void	zero_up(t_game *game);
void	one_up(t_game *game);
void	my_down(t_game *game);
void	one_down(t_game *game);
void	zero_down(t_game *game);
void	my_left(t_game *game);
void	zero_left(t_game *game);
void	one_left(t_game *game);
void	my_right(t_game *game);
void	zero_right(t_game *game);
void	one_right(t_game *game);
void	my_putchar(char c);
void	my_esc(t_term *term, struct termios *termios);
void	show_matches(char **matches, t_term *term, t_game *game);
void	create_game(t_game *game);
void	my_game(t_game *game);
void	my_keys(t_game *game, struct termios *termios, t_term *term);
void	my_keys_bis(t_game *game);
void	check_term(char *str);
void	check_tgetent(int x);
void	my_enter(t_game *game);
void	check_exit(t_game *game);
void	write_matches(t_term *term, char **matches, int a, int b);
void	put_allum(t_game *game);
void	aff_allum(t_game *game);
void	my_play(t_game *game);
void	base_game(t_game *game);
void	my_calc(t_game *game);
void	my_put_nbr(int nb);
void	aff_lines(int a);
void	check_matches(t_game *game, struct termios *termios, t_term *term);
void	my_calc_bis(t_game *game, int b, int c, int d);
void	my_check(t_game *game);
void	my_refresh(t_game *game, t_term *term);
char	*my_strxcpy(char *dest, char *src, char c);
int	calc_lines(int x);
int	my_exec(int c);
int     one_last(t_game *game, int a, int b);
int	calc_min(t_game *game, int a);
int	calc_addition(int a, int b);
int	my_strlen(char *str);
int	start(t_game *game);
int	allum_rest(t_game *game);
int	check_last(t_game *game, int a, int b);
int	ly_exception(t_game *game);
int	nbr_select(t_game *game);
int	allum_rest(t_game *game);
int	search_select(t_game *game);
int	my_getnbr(char *str);

#endif /* _MY_H_ */
