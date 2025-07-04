#include "libft.h"

char *ft_strstr(char *big_str, char *small_str)
{
  int i;
  int j;

  i = 0;
  while (big_str[i])
  {
    j = 0;
    while (big_str[i + j] && small_str[j] == big_str[i + j])
      j++;
    if (!small_str[j])
      return (big_str + i);
    i++;
  }
  return (NULL);
}

