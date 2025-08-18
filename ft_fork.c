/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:26:41 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 06:01:44 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_fork_error(char **table, t_exec *execute)
{
	char	*dest;
	int		status;

	ft_freetable(table);
	if (execute->cmd->error == STATUS_F)
		dest = ft_strjoin(execute->args[0], ERROR_F);
	if (execute->cmd->error == STATUS_D)
		dest = ft_strjoin(execute->args[0], ERROR_D);
	if (execute->cmd->error == STATUS_X)
		dest = ft_strjoin(execute->args[0], ERROR_X);
	if (!dest)
		ft_expend_malloc_faild();
	ft_putstr_fd(dest, 2);
	free(dest);
	status = execute->cmd->error;
	if (execute->cmd->error == STATUS_D)
		status = execute->cmd->error - 2;
	ft_clear();
	exit(status);
}

static void	ft_help(char **table)
{
	ft_putstr_fd(EMPTY_STR_ERROR, 2);
	ft_freetable(table);
	ft_clear();
	exit(127);
}

int	ft_fork(t_exec *execute)
{
	int		child;
	char	**table;

	table = ft_linked_to_envtable();
	child = fork();
	if (child == 0)
	{
		if (!(execute->args) || !(execute->args[0]))
		{
			ft_clear();
			exit(0);
		}
		if (!*(execute->args[0]))
			ft_help(table);
		if (execute->cmd->error)
			ft_fork_error(table, execute);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(execute->cmd->path, execute->args, table);
	}
	return (ft_freetable(table), child);
}

int	ft_before_forking(t_exec *execute)
{
	int	child;
	int	flag;
	int	status;

	signal(SIGINT, SIG_IGN);
	if (execute->next || execute->redi)
		ft_dup();
	while (execute)
	{
		if (ft_pipe(execute->next) == -1)
			return (ft_restor_fd(), -1);
		flag = ft_redi(execute);
		if (flag == -2)
		{
			execute = execute->next;
			continue ;
		}
		else if (flag == -1)
			return (perror("minishell"), ft_restor_fd(), -1);
		child = ft_fork(execute);
		if (child < 0)
			return (perror("minishell"), ft_restor_fd(), -1);
		execute = execute->next;
	}
	waitpid(child, &status, 0);
	wait(NULL);
	ft_signal();
	if (ft_global(NULL)->fd[0] > -1 && ft_global(NULL)->fd[1] > -1)
		ft_restor_fd();
	return (0);
}
