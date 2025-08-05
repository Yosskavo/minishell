/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:23:08 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/05 20:34:17 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_add_exec_list_back(t_exec **head, t_exec *new)
{
	t_exec	*tmp;

	if (!new)
		return (NULL);
	if (!*head)
		return (*head = new, (void *)1);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ((void *)1);
}

t_parce	*ft_list_last(t_parce *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	*ft_list_add_back(t_parce **lst, t_parce *new)
{
	if (!new || !lst)
		return (NULL);
	if (!*lst)
		return (*lst = new, new);
	new->previous = ft_list_last(*lst);
	new->previous->next = new;
	return (new);
}

static t_env	*ft_lst_last_env(t_env *env)
{
	while (env->next)
		env = env->next;
	return (env);
}

void	ft_lstadd_back_env(t_env **head, t_env *env)
{
	if (!*head)
		return (*head = env, (void)1);
	ft_lst_last_env(*head)->next = env;
}
