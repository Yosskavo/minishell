/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:26:41 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/16 16:23:53 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_fork(t_exec *execute)
{
	int	child;

	child = fork();
	if (child == 0)
	{
		if (!(execute->args) || !(execute->args[0]))
		{
			ft_clear_exec(&(ft_global(NULL)->execute));
			exit(0);
		}
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execvp(execute->args[0], execute->args);
		exit(0);
	}
	return (child);
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
