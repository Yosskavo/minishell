/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:30:53 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/21 04:12:48 by yel-mota         ###   ########.fr       */
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
		if (execute->tocken == ERROR)
		{
			ft_clear();
			exit(1);
		}
		if (execute->tocken != COMMAND)
			ft_built_in(execute);
		else
			ft_execve(execute);
		ft_clear();
		exit(ft_status(-1));
	}
	return (child);
}
