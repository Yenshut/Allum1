/*
** my_put_nbr.c for allum1 in /home/garcin_s/rendu/Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Fri Feb 14 10:07:08 2014 garcin_s
** Last update Fri Feb 14 10:07:08 2014 garcin_s
*/


#include "my.h"

void    	my_put_nbr(int nb)
{
  long long	nb2;
  int		count;
  long long	nb3;

  count = 1;
  nb2 = nb;
  if (nb2 < 0)
    {
      my_putchar('-');
      nb2 = nb2 * -1;
    }
  nb3 = nb2;
  while (nb3 >= 10)
    {
      nb3 = nb3 / 10;
      count = count * 10;
    }
  while (count >= 1)
    {
      my_putchar((nb2 / count) % 10 + 48);
      count = count / 10;
    }
}
