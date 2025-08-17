/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:23:12 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/17 03:10:52 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_clear_env(t_env **env)
{
	t_env	*tmp;

	tmp = (*env);
	while (tmp)
	{
		(*env) = (*env)->next;
		free(tmp->variable);
		free(tmp->value);
		free(tmp);
		tmp = (*env);
	}
}

void	ft_expend_free(t_parce *parce)
{
	free(parce->exp->exp);
	free(parce->exp->map);
	free(parce->exp);
	parce->exp = NULL;
}

void	ft_mini_clear_list(t_parce **lst)
{
	t_parce	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->fd_out > -1)
			close((*lst)->fd_out);
		if ((*lst)->fd_in > -1)
			close((*lst)->fd_in);
		free((*lst)->str);
		free((*lst)->map);
		free(*lst);
		(*lst) = NULL;
		(*lst) = tmp;
	}
}

void	ft_clear_exec(t_exec **execute)
{
	t_exec	*tmp;

	while (*execute)
	{
		tmp = (*execute)->next;
		ft_freetable((*execute)->args);
		if ((*execute)->cmd)
		{
			free((*execute)->cmd->path);
			free((*execute)->cmd);
		}
		ft_mini_clear_list(&((*execute)->redi));
		free((*execute));
		(*execute) = tmp;
	}
}

void	ft_clear_list(t_parce **lst)
{
	t_parce	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free((*lst)->map);
		if ((*lst)->fd_in > -1)
			close((*lst)->fd_in);
		if ((*lst)->fd_out > -1)
			close((*lst)->fd_out);
		if ((*lst)->exp)
		{
			ft_mini_clear_list(&((*lst)->exp->parce));
			ft_expend_free(*lst);
			(*lst)->exp = NULL;
		}
		free(*lst);
		(*lst) = tmp;
	}
}
