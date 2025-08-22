/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:31:45 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/22 01:34:03 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_fork_error(t_exec *execute)
{
	char	*dest;

	dest = ft_strjoin(execute->args[0], ERROR_D);
	if (!dest)
		ft_expend_malloc_faild();
	ft_putstr_fd(dest, 2);
	free(dest);
	ft_clear();
	exit(execute->cmd->error);
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
	if (execute->cmd->error == STATUS_D)
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
