/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:25:58 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 10:57:48 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_handle_sig_heredoc(int sig)
{
	(void)sig;
	exit(130);
}

static void ft_signal_heredoc()
{
	if (signal(SIGINT, &ft_handle_sig_heredoc) == SIG_ERR)
		return (perror("minishell"), exit(0));
	if (signal(SIGQUIT, SIG_IGN))
		return (perror("minishell"), exit(0));
}

static void ft_read_herdoc(t_parce *tmp)
{
	char *str;

	ft_signal_heredoc();
	while (1)
	{
		str = readline("->");
		if (!str)
			return ((void)ft_putstr_fd(HEREDOC_ERROR, 2));
		if (ft_strcmp(str, tmp->str))
			return ;
		if (!*str)
		{
			free(str);
			if (ft_putstr_fd("\n", tmp->fd_in) < 0)
				return ((void)perror("minishell"));
		}
		else
		{
			free(str);
			str = ft_strjoin(str, "\n");
			if (ft_putstr_fd(str, tmp->fd_in) < 0)
				return ((void)perror("minishell"));
		}
		free(str);
	}
	return ;
}

void *ft_fork_heredoc(t_parce *tmp)
{
	int	child;
	int status;

	child = fork();
	if (child < 0)
		return (perror("minishell"), NULL);
	if (child == 0)
	{
		ft_read_herdoc(tmp->next);
		return (NULL);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			ft_status(WEXITSTATUS(status));
	}
	return ((void *)1);
}
