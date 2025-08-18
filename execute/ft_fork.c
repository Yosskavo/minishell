/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:26:41 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 21:07:40 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_fork(t_exec *execute)
{
	int	child;

	child = fork();
	if (child == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		// if (ft_global(NULL)->old_fd != -1)
		// 	close(ft_global(NULL)->old_fd);
		if (execute->tocken != COMMAND)
			ft_built_in(execute);
		else
			ft_execve(execute);
		ft_clear();
		exit(ft_status(-1));
	}
	return (child);
}
