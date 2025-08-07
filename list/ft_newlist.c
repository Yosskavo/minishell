/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:23:19 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/05 20:40:28 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_exec	*ft_newexec_lst(void)
{
	t_exec	*new;

	new = malloc(sizeof(t_exec));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_exec));
	return (new);
}

t_parce	*ft_newlist(char *str)
{
	t_parce	*new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(t_parce));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_parce));
	new->str = str;
	new->fd_in = -1;
	new->fd_out = -1;
	return (new);
}

t_env	*ft_lstnew_env(char *var, char *val)
{
	t_env	*new;

	if (!var || !val)
		return (free(var), free(val), NULL);
	new = malloc(sizeof(t_env));
	if (!new)
		return (free(var), free(val), NULL);
	new->value = val;
	new->variable = var;
	new->next = NULL;
	return (new);
}
