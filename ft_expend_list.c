/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:01:20 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/02 21:23:35 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_expend_mini_free(t_parce *parce)
{
	free(parce->str);
	free(parce->map);
	free(parce->exp->exp);
	free(parce->exp->map);
	free(parce->exp);
	parce->str = NULL;
	parce->map = NULL;
	parce->exp = NULL;
}

static void	ft_expend_filename_expend_null_node(t_parce **head, t_parce *new)
{
	ft_expend_mini_free(new);
	new->tocken = AMBIGUOUS;
	ft_list_add_back(head, new);
}

static void	ft_expend_handle_list(t_parce **head, t_parce *new)
{
	if (new->tocken == FILENAME_EXPEND && !new->exp->parce)
	{
		ft_expend_filename_expend_null_node(head, new);
		return ;
	}
	else if (new->tocken == EXPEND && !new->exp->parce)
	{
		ft_expend_mini_free(new);
		free(new);
		new = NULL;
		return ;
	}
	ft_list_add_back(head, new->exp->parce);
	new->exp->parce = NULL;
	ft_expend_mini_free(new);
	free(new);
}

t_parce	*ft_expend_link_list(t_parce *parce)
{
	t_parce	*mover;
	t_parce	*new_head;

	mover = parce;
	new_head = NULL;
	while (mover)
	{
		parce = parce->next;
		mover->next = NULL;
		mover->previous = NULL;
		if (mover->tocken == FILENAME_EXPEND || mover->tocken == EXPEND)
			ft_expend_handle_list(&new_head, mover);
		else
			ft_list_add_back(&new_head, mover);
		mover = parce;
	}
	return (new_head);
}
