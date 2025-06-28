/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:23:19 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/26 15:39:18 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_parce *ft_newlist(char *str)
{
	t_parce *new;
	
	if (!str)
		return (NULL);
	new = malloc(sizeof(t_parce));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}
