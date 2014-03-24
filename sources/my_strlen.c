/*
** my_sterlen.c for my_sterlen in /home/garcin_s/rendu/Piscine-C-Jour_04
** 
** Made by garcin
** Login   <garcin_s@epitech.net>
** 
** Started on  Thu Oct  3 13:15:19 2013 garcin
** Last update Fri Jan 31 11:43:33 2014 garcin_s
*/

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a++;
  return (a);
}
