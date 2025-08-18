/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executable_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 03:36:10 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 05:30:27 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_excute_command_status(t_exec *execute, char *path)
{
	struct stat	node;

	if (stat(path, &node))
		return (1);
	if (S_ISDIR(node.st_mode))
		return (3);
	if (access(path, X_OK))
		return (execute->cmd->path = path, execute->cmd->error = STATUS_X, 2);
	execute->cmd->error = 0;
	execute->cmd->path = path;
	return (0);
}

void	ft_execute_check_path(t_exec *execute)
{
	int	flag;

	execute->cmd->path = ft_strdup(execute->args[0]);
	if (!(execute->cmd->path))
		ft_expend_malloc_faild();
	flag = ft_excute_command_status(execute, execute->cmd->path);
	if (flag == 3)
		execute->cmd->error = STATUS_D;
	else if (flag == 1)
		execute->cmd->error = STATUS_F;
}

static void	ft_help(t_exec *execute, char *path)
{
	if (!(execute->cmd->path))
	{
		execute->cmd->path = path;
		execute->cmd->error = STATUS_F;
	}
}

void	ft_execute_creat_path(t_exec *execute)
{
	char	*path;
	char	**table;
	int		i;

	path = ft_search_expend("PATH", ft_strlen("PATH"));
	if (!path)
		return (ft_execute_check_path(execute));
	table = ft_split(path, ':');
	if (!table)
		ft_expend_malloc_faild();
	i = 0;
	path = NULL;
	while (table[i])
	{
		free(path);
		path = ft_strcjoin(table[i], execute->args[0], '/');
		if (!path)
			return (ft_freetable(table), ft_expend_malloc_faild());
		if (!ft_excute_command_status(execute, path))
			return (ft_freetable(table), (void)1);
		i++;
	}
	return (ft_help(execute, path), ft_freetable(table));
}
