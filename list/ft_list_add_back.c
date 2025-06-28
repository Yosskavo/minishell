/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:23:08 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/27 09:42:59 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_parce *ft_list_last(t_parce *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void *ft_list_add_back(t_parce **lst, t_parce *new)
{
	if (!new || !lst)
		return (NULL);
	if (!*lst)
		return (*lst = new, new);
	ft_list_last(*lst)->next = new;
	return (new);
}