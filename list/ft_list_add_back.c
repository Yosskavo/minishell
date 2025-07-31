/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:23:08 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/31 12:09:02 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
	t_parce	*tmp;

	if (!new || !lst)
		return (NULL);
	if (!*lst)
		return (*lst = new, new);
	tmp = ft_list_last(*lst);
	tmp->next = new;
	new->previous = tmp;
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
