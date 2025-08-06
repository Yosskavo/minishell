/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/06 12:51:47 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_last_check(t_exec *execute)
{
	while (execute)
	{
		if (execute->parce)
			if (ft_check_built_in(execute->cmd))
				execute->cmd->tocken = BUILT_IN;
		execute = execute->next;
	}
}

int	ft_parcing(t_mini *mini)
{
	if (ft_spliting(mini->str, &(mini->start)) == -1)
		return (-1);
	if (ft_tokenization(mini->start) == -1)
		return (ft_clear_list(&(mini->start)), -1);
	ft_expention(mini);
	ft_delete_qots(mini->start);
	if (ft_heredoc(mini->start))
		return (ft_clear_list(&(mini->start)), -1);
	mini->start = ft_clean_before_exec(mini->start);
	if (!(mini->start))
		return (-1);
	mini->execute = ft_transefarce();
	ft_last_check(mini->execute);
	mini->start = NULL;
	return (0);
}

int	ft_start(void)
{
	t_mini	*mini;

	mini = ft_global(NULL);
	if (ft_parcing(mini) == -1)
		return (-1);
	print(mini->execute);
	ft_clear_exec(&(mini->execute));
	mini->execute = NULL;
	return (0);
}
