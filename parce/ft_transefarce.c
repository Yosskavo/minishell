/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transefarce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 08:52:16 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/16 15:59:53 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	**ft_newexec_table(t_parce *parce)
{
	int		i;
	int		size;
	char	**dest;

	size = ft_many_tocken_between_tocken(parce, WORD, PIPE);
	dest = malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (parce && parce->tocken != PIPE)
	{
		if (parce->tocken == WORD)
		{
			dest[i] = ft_strdup(parce->str);
			if (!dest[i])
				return (ft_freetable(dest), NULL);
			i++;
		}
		parce = parce->next;
	}
	dest[i] = NULL;
	return (dest);
}

static t_exec	*ft_exec_new_list(t_parce *parce)
{
	t_exec	*head;
	int		i;
	int		size;

	head = NULL;
	size = ft_many_tocken(parce, PIPE) + 1;
	i = 0;
	while (i < size)
	{
		if (!ft_add_exec_list_back(&head,
				ft_newexec_lst(ft_newexec_table(parce))))
			return (ft_free_exec_alloc(&head), ft_expend_malloc_faild(), NULL);
		while (parce && parce->tocken != PIPE)
			parce = parce->next;
		if (parce && parce->tocken == PIPE)
			parce = parce->next;
		i++;
	}
	return (head);
}

static void	ft_help(t_parce *parce, t_exec **head, t_exec **tmp_head,
		t_parce **tmp)
{
	*head = ft_exec_new_list(parce);
	*tmp = parce;
	*tmp_head = *head;
}

t_exec	*ft_transefarce(t_parce *parce)
{
	t_exec	*head;
	t_exec	*tmp_head;
	t_parce	*trach_head;
	t_parce	*tmp;

	ft_help(parce, &head, &tmp_head, &tmp);
	trach_head = NULL;
	while (parce)
	{
		tmp = tmp->next;
		parce->next = NULL;
		parce->previous = NULL;
		if (parce->tocken == PIPE)
		{
			ft_list_add_back(&trach_head, parce);
			head = head->next;
		}
		else if (parce->tocken == WORD)
			ft_list_add_back(&trach_head, parce);
		else
			ft_list_add_back(&(head->redi), parce);
		parce = tmp;
	}
	return (ft_mini_clear_list(&trach_head), tmp_head);
}
