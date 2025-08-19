/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:31:09 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 05:31:12 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_executable_check(t_exec *execute)
{
	if (!(execute->args) || !(execute->args[0]))
		return ;
	execute->cmd = malloc(sizeof(t_cmd));
	if (!(execute->cmd))
		ft_expend_malloc_faild();
	ft_memset(execute->cmd, 0, sizeof(t_cmd));
	if (ft_strchr(execute->args[0], '/'))
		return (ft_execute_check_path(execute));
	else
		return (ft_execute_creat_path(execute));
}

void	ft_executable(void)
{
	t_exec	*execute;

	execute = ft_global(NULL)->execute;
	while (execute)
	{
		if (execute->tocken == COMMAND)
			ft_executable_check(execute);
		execute = execute->next;
	}
}
