/*
** strxcpy.c for my_select in /home/garcin_s/rendu/PSU_2013_my_select
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Sun Jan 19 04:58:21 2014 garcin_s
** Last update Fri Feb 14 10:13:57 2014 garcin_s
*/
#include "my.h"

char	*my_strxcpy(char *dest, char *src, char c)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (src[a] != c)
    a++;
  a++;
  while (src[a] != '\0')
    {
      dest[b] = src[a];
      b++;
      a++;
    }
  dest[b] = '\0';
  return (dest);
}
