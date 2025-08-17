/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/17 00:03:30 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_check_built_in(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "echo"))
		return (1);
	if (!ft_strcmp(str, "pwd"))
		return (2);
	if (!ft_strcmp(str, "export"))
		return (3);
	if (!ft_strcmp(str, "unset"))
		return (4);
	if (!ft_strcmp(str, "env"))
		return (5);
	if (!ft_strcmp(str, "cd"))
		return (6);
	if (!ft_strcmp(str, "exit"))
		return (7);
	return (0);
}

static void	ft_last_check(t_exec *execute)
{
	while (execute)
	{
		if (execute->args[0])
		{
			if (ft_check_built_in(execute->args[0]))
				execute->tocken = BUILT_IN;
			else
				execute->tocken = COMMAND;
		}
		execute = execute->next;
	}
	ft_executable();
}

int	ft_parcing(t_mini *mini)
{
	if (ft_spliting(mini->str, &(mini->start)) == -1)
		return (free(mini->str), mini->str = NULL, -1);
	free(mini->str);
	mini->str = NULL;
	if (ft_tokenization(mini->start) == -1)
		return (ft_clear_list(&(mini->start)), -1);
	ft_expention(mini);
	ft_delete_qots(mini->start);
	if (ft_heredoc(mini->start))
		return (ft_clear_list(&(mini->start)), -1);
	mini->start = ft_clean_before_exec(mini->start);
	if (!(mini->start))
		return (-1);
	mini->execute = ft_transefarce(mini->start);
	mini->start = NULL;
	ft_last_check(mini->execute);
	return (0);
}

int	ft_start(void)
{
	t_mini	*mini;

	mini = ft_global(NULL);
	if (ft_parcing(mini) == -1)
		return (-1);
	if (ft_execute(mini) == -1)
		return (-1);
	ft_clear_exec(&(mini->execute));
	mini->execute = NULL;
	return (0);
}
