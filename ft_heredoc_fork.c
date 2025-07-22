/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:25:58 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 16:24:10 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static t_mini *ft_global(t_mini *mini)
{
	static t_mini *tmp;

	if (!mini)
		return (tmp);
	tmp = mini;
	return (tmp);
}

static void	ft_free_all_heredoc(void)
{
	t_mini *mini;

	mini = ft_global(NULL);
	ft_freetable(mini->env);
	ft_clear_list(&(mini->start));
	free(mini->str);
	free(mini);
}

static void	ft_handle_sig_heredoc(int sig)
{
	t_mini *tmp;

	(void)sig;
	tmp = ft_global(NULL);
	ft_freetable(tmp->env);
	ft_clear_list(&(tmp->start));
	free(tmp->str);
	free(tmp);
	exit(130);
}

static void ft_signal_heredoc()
{
	if (signal(SIGINT, &ft_handle_sig_heredoc) == SIG_ERR)
		return (perror("minishell"), exit(0));
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (perror("minishell"), exit(0));
}


static void ft_read_herdoc(t_parce *tmp)
{
	char *str;
	char *dest;

	ft_signal_heredoc();
	while (1)
	{
		str = readline("->");
		if (!str)
			return (ft_free_all_heredoc(), (void)ft_putstr_fd(HEREDOC_ERROR, 2));
		if (!ft_strcmp(str, tmp->str))
			return (ft_free_all_heredoc());
		if (!*str)
		{
			if (ft_putstr_fd("\n", tmp->fd_in) < 0)
				return (free(str), perror("minishell"));
		}
		else
		{
			dest = ft_strjoin(str, "\n");
			if (ft_putstr_fd(dest, tmp->fd_in) < 0)
				return (free(str), free(dest), perror("minishell"));
			free(dest);
		}
		free(str);
	}
}

void *ft_fork_heredoc(t_parce *tmp)
{
	int	child;
	int status;

	child = fork();
	if (child < 0)
		return (perror("minishell"), NULL);
	ft_global(tmp->mini);
	if (child == 0)
	{
		ft_read_herdoc(tmp->next);
		exit(0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			ft_status(WEXITSTATUS(status));
	}
	return ((void *)1);
}
