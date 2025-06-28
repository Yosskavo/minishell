/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:23:12 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/26 16:00:09 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_clear_list(t_parce **lst)
{
	t_parce *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		(*lst)->str = NULL;
		free(*lst);
		(*lst) = NULL;
		(*lst) = tmp;
	}
}
