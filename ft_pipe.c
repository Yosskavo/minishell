/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:56:36 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/09 15:41:00 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_help(int *old_fd, int fd[2])
{
	if (*old_fd > -1)
	{
		close(*old_fd);
		*old_fd = -1;
	}
	if (fd[0] > -1)
		close(fd[0]);
	if (fd[1] > -1)
		close(fd[1]);
	return (-1);
}

int	ft_pipe(void *flag)
{
	int		fd[2];
	t_mini	*mini;

	mini = ft_global(NULL);
	if (!flag && mini->old_fd == -1)
		return (0);
	fd = {-1, -1};
	if (mini->old_fd == -1 && !flag)
		return (0);
	if (pipe(fd) < 0)
		return (ft_help(&(mini->old_fd), fd));
	if ((flag && dup2(STDIN_FILENO, fd[1]) < 0))
		return (ft_help(&(mini->old_fd), fd));
	close(fd[1]);
	if (old_fd && dup2(STDOUT_FILENO, fd[0]) < 0)
		return (ft_help(&(mini->old_fd), fd));
	if (mini->old_fd == -1)
		mini->old_fd = fd[0];
	else
		close(fd[0]);
	return (0);
}
