/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:26:41 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/11 19:59:52 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_fork(t_exec *execute)
{
	int		child;
	char	*str[] = {execute->cmd->str, NULL};

	child = fork();
	if (child == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execvp(execute->cmd->str, str);
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
			return (ft_restor_fd(), -1);
		child = ft_fork(execute);
		if (child < 0)
			return (perror("minishell"), ft_restor_fd(), -1);
		execute = execute->next;
	}
	waitpid(child, &status, 0);
	wait(NULL);
	ft_signal();
	ft_restor_fd();
	return (0);
}
