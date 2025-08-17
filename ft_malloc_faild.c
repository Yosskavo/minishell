/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_faild.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:35:08 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/17 03:10:30 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_free_exec_alloc(t_exec **head)
{
	t_exec	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		ft_freetable((*head)->args);
		if ((*head)->cmd)
		{
			free((*head)->cmd->path);
			free((*heaed)->cmd);
		}
		free((*head));
		*head = tmp;
	}
	*head = NULL;
}

void	ft_malloc_faild(void)
{
	t_mini	*mini;

	mini = ft_global(NULL);
	if (mini->env)
		ft_clear_env(&(mini->env));
	if (mini->start)
		ft_clear_list(&(mini->start));
	free(mini->str);
	free(mini);
	ft_putstr_fd(MALLOC_FAILD, 2);
	exit(1);
}

void	ft_expend_malloc_faild(void)
{
	t_mini	*mini;

	mini = ft_global(NULL);
	if (mini->env)
		ft_clear_env(&(mini->env));
	if (mini->start)
		ft_mini_clear_list(&(mini->start));
	if (mini->execute)
		ft_free_exec_alloc(&(mini->execute));
	free(mini->str);
	free(mini);
	ft_putstr_fd(MALLOC_FAILD, 2);
	exit(1);
}
