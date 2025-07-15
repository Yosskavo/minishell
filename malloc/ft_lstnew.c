/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:22:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 22:49:40 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_list *ft_lstnew(void *ptr)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		perror("minishell");
		exit(1);
	}
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

