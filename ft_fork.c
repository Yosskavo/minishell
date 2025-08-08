/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:26:41 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/07 17:28:26 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_before_forking(t_exec *execute)
{
	int	child;
	int	status;

	if (execute->next || execute->redi)
		ft_dup();
	while (execute)
	{
		if (execute->pipe)
			ft_pipe();
		if (execute->redi)
			ft_redi();
		child = ft_fork(execute);
		if (child < 0)
			return ;
		execute = execute->next;
	}
	waitpid(child, &status, 0);
	wait(NULL);
}
