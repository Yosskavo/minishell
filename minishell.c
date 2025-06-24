#include <readline/readline.h>
#include <stdlib.h>
#include <readline/history.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*dest;
  size_t      i;

	size = sizeof(char) * (ft_strlen(s) + 1);
	dest = malloc(size);
	if (dest == NULL)
		return (NULL);
  i = 0;
  while (s[i])
  {
    dest[i] = s[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

int main ()
{
  char *str;

  str = ft_strdup("");
  while (1)
  {
    free(str);
    str = readline("<-mini->");
    if (!str)
      return (1);
    if (*str)
      add_history(str);
    printf("%s\n", str);
  }
  
  rl_cleanup_after_signal();
  rl_clear_history();
}
