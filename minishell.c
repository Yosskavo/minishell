#include <readline/readline.h>
#include <stdlib.h>
// #include <readline/history.h>

void ft_parcing_it(char *str)
{
  printf("%s\n", str);
}

int ft_start()
{
  char *str;

  while (1)
  {
    str = readline("mini-->>");
    if (!str)
      return (perror("minishell"), 1);
    if (*str)
      ft_parcing_it(str);
    free(str);
  }
}

int main ()
{
  ft_start();
}
