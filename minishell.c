/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:12:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/31 21:30:57 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_valid_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (str[i]);
}

static int	ft_start(t_mini *mini)
{
	ft_signal();
	while (1)
	{
		mini->str = readline("¿ ");
		if (!mini->str)
			return (-1);
		if (*(mini->str) && ft_valid_input(mini->str))
		{
			add_history(mini->str);
			ft_parcing(mini);
		}
		free(mini->str);
	}
	return (0);
}

static void	ft_setup(int ac, char **av, char **env)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	if (!mini)
		return (perror("minishell"), exit(2), (void)1);
	ft_memset(mini, 0, sizeof(t_mini));
	ft_global(mini);
	mini->env = ft_envcpy(env);
	ft_start(mini);
	ft_clear_env(&(mini->env));
	free(mini);
	(void)ac;
	(void)av;
}

int	main(int ac, char **av, char **env)
{
	ft_setup(ac, av, env);
	printf("exit");
	return (0);
}
