/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:44:03 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/17 21:53:19 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_execute_check_path(t_exec *execute)
{
	execute->cmd->path = ft_strdup(execute->args[0]);
	if (!(execute->cmd->path))
		ft_expend_malloc_faild();
	if (ft_excute_command_status(execute, execute->cmd->path))
		;
}

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
		return (ft_execute_creat_path());
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
