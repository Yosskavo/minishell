/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:25:58 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/05 18:32:22 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	*ft_fork_heredoc(t_parce *tmp)
{
	int	child;
	int	status;

	child = fork();
	if (child < 0)
		return (perror("minishell"), NULL);
	if (child == 0)
	{
		ft_read_herdoc(tmp);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		wait(&status);
		if (WIFEXITED(status))
			ft_status(WEXITSTATUS(status));
		close(tmp->fd_in);
		tmp->fd_in = -1;
		ft_signal();
		if (ft_status(-1) == 130)
			return (NULL);
	}
	return ((void *)1);
}
