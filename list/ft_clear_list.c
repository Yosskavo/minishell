/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:23:12 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/31 14:45:39 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	print_env(t_env *env)
{
	while (env)
	{
		printf("%s = %s\n", env->variable, env->value);
		env = env->next;
	}
}

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
}

void	ft_clear_list(t_parce **lst)
{
	t_parce	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->fd_in > -1)
			close((*lst)->fd_in);
		if ((*lst)->fd_out > -1)
			close((*lst)->fd_out);
		free((*lst)->str);
		if ((*lst)->exp)
			ft_expend_free(*lst);
		free(*lst);
		(*lst) = tmp;
	}
}
