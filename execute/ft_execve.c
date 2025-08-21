/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:31:45 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/21 03:35:32 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_fork_error(t_exec *execute)
{
	char	*dest;
	int		status;

	if (execute->cmd->error == STATUS_F)
		dest = ft_strjoin(execute->args[0], ERROR_F);
	if (execute->cmd->error == STATUS_D)
		dest = ft_strjoin(execute->args[0], ERROR_D);
	if (execute->cmd->error == STATUS_X)
		dest = ft_strjoin(execute->args[0], ERROR_X);
	if (execute->cmd->error == STATUS_N)
		dest = ft_strjoin(execute->args[0], ERROR_N);
	if (!dest)
		ft_expend_malloc_faild();
	ft_putstr_fd(dest, 2);
	free(dest);
	status = execute->cmd->error;
	if (execute->cmd->error == STATUS_D || execute->cmd->error == STATUS_N)
		status = execute->cmd->error - 2;
	ft_clear();
	exit(status);
}

static void	ft_help(void)
{
	ft_putstr_fd(EMPTY_STR_ERROR, 2);
	ft_clear();
	exit(127);
}

void	ft_execve(t_exec *execute)
{
	char	**table;

	if (ft_global(NULL)->old_fd > -1)
		close(ft_global(NULL)->old_fd);
	if (!(execute->args) || !(execute->args[0]))
	{
		ft_clear();
		exit(0);
	}
	if (!*(execute->args[0]))
		ft_help();
	if (execute->cmd->error)
		ft_fork_error(execute);
	table = ft_linked_to_envtable();
	if (!table)
		return (ft_putstr_fd(MALLOC_FAILD, 2), ft_clear(), exit(1));
	execve(execute->cmd->path, execute->args, table);
	perror("minishell");
	ft_freetable(table);
	ft_clear();
	exit(1);
}
