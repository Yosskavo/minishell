/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:01:20 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/01 11:01:25 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_expend_list(t_parce **head, t_parce *new)
{
	t_parce	*tmp;

	tmp = new->exp->parce;
	if (!tmp->next && !tmp->previous)
	{
		ft_clear_list(new);
		*head = tmp;
		return ;
	}
	if (!tmp->next)
	{
	}
}
