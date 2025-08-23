/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_before_exec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:33:16 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/04 16:04:39 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_help_clean(t_parce *tmp)
{
	if (tmp->tocken == FILENAME_EXPEND)
		tmp->tocken = FILENAME;
	else if (tmp->tocken == EXPEND)
		tmp->tocken = WORD;
	free(tmp->map);
	tmp->map = NULL;
}

t_parce	*ft_clean_before_exec(t_parce *parce)
{
	t_parce	*new_head;
	t_parce	*trach_head;
	t_parce	*tmp;

	trach_head = NULL;
	new_head = NULL;
	tmp = parce;
	while (tmp)
	{
		parce = parce->next;
		tmp->next = NULL;
		tmp->previous = NULL;
		ft_help_clean(tmp);
		if (tmp->tocken == DELEMITER)
			ft_list_add_back(&trach_head, tmp);
		else
			ft_list_add_back(&new_head, tmp);
		tmp = parce;
	}
	ft_clear_list(&trach_head);
	return (new_head);
}
