/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:56:36 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/12 22:35:17 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_help(int *old_fd, int fd[2])
{
	perror("minishell");
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

static int	ft_stdout(void *flag, int fd[2], int *old_fd)
{
	if (flag)
	{
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			return (ft_help(old_fd, fd), -1);
	}
	else if (!flag)
	{
		if (dup2(ft_global(NULL)->fd[1], STDOUT_FILENO) < 0)
			return (ft_help(old_fd, fd), -1);
		close(ft_global(NULL)->fd[1]);
	}
	return (0);
}

static int	ft_stdin(int *old_fd, int fd[2])
{
	if (*old_fd == -1)
		return (0);
	if (dup2(*old_fd, STDIN_FILENO) < 0)
		return (ft_help(old_fd, fd), -1);
	return (0);
}

static void	ft_update_fd(void *flag, int *old_fd, int fd[2])
{
	if (*old_fd == -1)
		*old_fd = fd[0];
	else if (!flag)
	{
		close(*old_fd);
		*old_fd = -1;
		close(fd[0]);
	}
	else
	{
		close(*old_fd);
		*old_fd = fd[0];
	}
	fd[0] = -1;
	close(fd[1]);
	fd[1] = -1;
}

int	ft_pipe(void *flag)
{
	int		fd[2];
	t_mini	*mini;

	mini = ft_global(NULL);
	if (mini->old_fd == -1 && !flag)
		return (0);
	fd[0] = -1;
	fd[1] = -1;
	if (pipe(fd) < 0)
		return (ft_help(&(mini->old_fd), fd));
	ft_stdout(flag, fd, &(mini->old_fd));
	ft_stdin(&(mini->old_fd), fd);
	ft_update_fd(flag, &(mini->old_fd), fd);
	return (0);
}
