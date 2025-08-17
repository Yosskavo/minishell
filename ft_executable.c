/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:44:03 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/17 03:38:15 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_execute_search_expend(char *str)
{
	t_env	*env;

	env = ft_global(NULL)->env;
	while (env)
	{
		if (!ft_strcmp(env, str))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

static void	ft_execute_fix_path(t_exec *execute)
{
	char	*tmp;

	tmp = ft_search_expend(PWD);
	execute->cmd->path = ft_strjoin(tmp, execute->args[0]);
	if (!(execute->cmd->path))
		ft_expend_malloc_faild();
}

static void	ft_executable_check(t_exec *execute)
{
	if (!(execute->args) || !(execute->args[0]))
		return ;
	execute->cmd = malloc(sizeof(t_cmd));
	if (!(execute->cmd))
		ft_expend_malloc_faild();
	if (*(execute->args[0]) == '/')
		execute->cmd->path = ft_strdup(args[0]);
	else if (ft_strchr(execute->args[0], '/'))
		ft_execute_fix_path(execute);
	else
		return (ft_execute_creat_path());
	ft_execute_path();
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
