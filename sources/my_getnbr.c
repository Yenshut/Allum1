/*
** my_getnbr.c for allum1 in /home/garcin_s/rendu/Allum1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Fri Feb 14 10:06:50 2014 garcin_s
** Last update Fri Feb 14 10:06:50 2014 garcin_s
*/


int	my_getnbr(char *str)
{
  int	count;
  int	s;
  int	nbr;

  s = 1;
  count = 0;
  while (str[count] != '\0' && (str[count] == '+' || str[count] == '-'))
    {
      if (str[count] == '-')
	{
	  s = s * -1;
	}
      count = count +1;
    }
  str = str + count;
  nbr = 0;
  count = 0;
  while (str[count] >= '0' && str[count] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr -(str[count]- '0');
      count = count +1;
    }
  return (nbr * s * -1);
}
