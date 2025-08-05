/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:25:58 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/05 13:37:26 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

// static void	ft_handle_sig_heredoc(int sig)
// {
// 	t_mini	*tmp;
//
// 	tmp = ft_global(NULL);
// 	ft_clear_env(&(tmp->env));
// 	ft_mini_clear_list(&(tmp->start));
// 	free(tmp->str);
// 	free(tmp);
// 	rl_clear_history();
// 	exit(130);
// }
//
// static void	ft_signal_heredoc(void)
// {
// 	if (signal(SIGINT, &ft_handle_sig_heredoc) == SIG_ERR)
// 		return (perror("minishell"), exit(0));
// 	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
// 		return (perror("minishell"), exit(0));
// }

void	*ft_fork_heredoc(t_parce *tmp)
{
	int	child;
	int	status;

	child = fork();
	if (child < 0)
		return (perror("minishell"), NULL);
	ft_global_var(1);
	if (child == 0)
	{
		ft_read_herdoc(tmp);
		exit(0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			ft_status(WEXITSTATUS(status));
		close(tmp->fd_in);
		tmp->fd_in = -1;
		if (ft_status(-1) == 130)
			return (NULL);
	}
	ft_global_var(0);
	return ((void *)1);
}
