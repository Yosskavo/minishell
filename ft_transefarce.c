/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transefarce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:50:46 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/05 22:56:49 by yel-mota         ###   ########.fr       */
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
	t_exec	*head;
	t_exec	*tmp_exec;

	tmp = ft_global(NULL)->start;
	head = ft_new_exec_list(tmp);
	tmp_exec = head;
	while (tmp)
	{
		parce = tmp->next;
		tmp->next = NULL;
		tmp->previous = NULL;
		if (parce->tocken == PIPE)
		{
			ft_list_add_back(&(trach_head), tmp);
			head = head->next;
		}
		else if (parce->tocken == WORD)
			ft_list_add_back(&(head->cmd), tmp);
		else
			ft_list_add_back(&(head->redi), tmp);
		tmp = parce;
	}
	return (ft_mini_clear_list(&trach_head), tmp_exec);
}
