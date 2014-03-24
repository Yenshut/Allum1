/*
** my_putchar.c for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Thu Feb  6 09:16:50 2014 garcin_s
** Last update Thu Feb  6 09:22:22 2014 garcin_s
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
