/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transefarce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:50:46 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/06 12:33:21 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_many_pipe(t_parce *parce)
{
	int	size;

	size = 0;
	while (parce)
	{
		if (parce->tocken == PIPE)
			size++;
		parce = parce->next;
	}
	return (size + 1);
}

t_exec	*ft_new_exec_list(t_parce *parce)
{
	t_exec	*head;
	int		i;
	int		size;

	size = ft_many_pipe(parce);
	i = 0;
	head = NULL;
	while (i < size)
	{
		if (!ft_add_exec_list_back(&head, ft_newexec_lst()))
			return (ft_free_exec_alloc(&head), ft_expend_malloc_faild(), NULL);
		i++;
	}
	return (head);
}

t_exec	*ft_transefarce(void)
{
	t_parce	*parce;
	t_parce	*trach_head;
	t_parce	*tmp;
	t_exec	*tmp_head;
	t_exec	*head;

	tmp = ft_global(NULL)->start;
	head = ft_new_exec_list(tmp);
	tmp_head = head;
	trach_head = NULL;
	parce = tmp;
	while (tmp)
	{
		parce = parce->next;
		tmp->next = NULL;
		tmp->previous = NULL;
		if (tmp->tocken == PIPE)
		{
			ft_list_add_back(&(trach_head), tmp);
			head = head->next;
		}
		else if (tmp->tocken == WORD)
			ft_list_add_back(&(head->cmd), tmp);
		else
			ft_list_add_back(&(head->redi), tmp);
		tmp = parce;
	}
	return (ft_mini_clear_list(&trach_head), tmp_head);
}
