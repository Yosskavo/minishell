/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:31:17 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 10:17:03 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_execute_start(t_exec *execute)
{
	int	flag;

	// int	child;
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
			return (ft_restor_fd(), -1);
		execute->child = ft_fork(execute);
		if (execute->child < 0)
			return (perror("minishell"), ft_restor_fd(), -1);
		execute = execute->next;
	}
	// close(ft_global(NULL)->old_fd);
	return (10);
}

static int	ft_before_forking(t_exec *execute)
{
	int	child;

	signal(SIGINT, SIG_IGN);
	if (execute->next || execute->redi)
		ft_dup();
	child = ft_execute_start(execute);
	if (child < 0)
		return (wait(NULL), ft_status(1), -1);
	if (ft_global(NULL)->fd[0] > -1 && ft_global(NULL)->fd[1] > -1)
		ft_restor_fd();
	ft_wait(execute);
	ft_signal();
	return (0);
}

static int	ft_before_built_in(t_exec *execute)
{
	if (execute->redi)
	{
		ft_dup();
		if (ft_redi(execute) < 0)
			return (-1);
	}
	ft_built_in(execute);
	if (ft_global(NULL)->fd[0] > -1 && ft_global(NULL)->fd[1] > -1)
		ft_restor_fd();
	return (0);
}

int	ft_execute(t_mini *mini)
{
	if (!(mini->execute->next) && mini->execute->tocken != COMMAND)
		return (ft_before_built_in(mini->execute));
	else
		return (ft_before_forking(mini->execute));
}
