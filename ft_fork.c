/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:26:41 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/09 17:30:05 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_fork(t_exec *execute)
{
	int		child;
	char	*str;

	str = "";
	child = fork();
	if (child == 0)
	{
		execvp(execute->cmd->str, &str);
	}
	return (child);
}

int	ft_before_forking(t_exec *execute)
{
	int	child;
	int	status;

	if (execute->next || execute->redi)
		ft_dup();
	while (execute)
	{
		if (ft_pipe(execute->next) == -1)
			return (ft_restor_fd(), -1);
		if (ft_redi(execute) == -1)
			return (ft_restor_fd(), -1);
		child = ft_fork(execute);
		if (child < 0)
			return (perror("minishell"), ft_restor_fd(), -1);
		execute = execute->next;
	}
	waitpid(child, &status, 0);
	wait(NULL);
	ft_restor_fd();
	return (0);
}
