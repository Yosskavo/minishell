/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:12:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/12 10:01:08 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_handle_sig(int sig)
{
	if (SIGINT == sig)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}


static void ft_signal(void)
{
	signal(SIGINT, &ft_handle_sig);
	signal(SIGQUIT, SIG_IGN);
}

static int	ft_start(t_mini *mini)
{
	char	*str;

	ft_signal();
	while (1)
	{
		str = readline("mini-->");
		if (!str)
			return (-1);
		if (*str)
		{
			add_history(str);
			ft_parcing(str, mini);
		}
		free(str);
	}
	return (0);
}

static char	**ft_envcpy(int ac, char **av, char **env)
{
	char	**dest_table;
	int		i;

	(void)ac;
	(void)av;
	dest_table = malloc(sizeof(char *) * (ft_lengh_of_table(env) + 1));
	if (!dest_table)
	{
		ft_puterror(0);
		return (NULL);
	}
	i = 0;
	while (env[i])
	{
		dest_table[i] = ft_strdup(env[i]);
		if (!dest_table[i])
		{
			ft_puterror(0);
			ft_freetable(dest_table);
			return (NULL);
		}
		i++;
	}
	dest_table[i] = NULL;
	return (dest_table);
}

int	main(int ac, char **av, char **env)
{
	t_mini	mini;

	mini.env = ft_envcpy(ac, av, env);
	if (!(mini.env))
		return (1);
	ft_start(&mini);
	ft_freetable(mini.env);
}
