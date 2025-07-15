/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:24:37 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 16:49:09 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_list	*ft_save_linkde(t_list *new, int i)
{
	static t_list *head;

	if (i)
	{
		head = new;
	}
	return (head);
}

void ft_clean_up(void)
{
	ft_lstclear(ft_sace_linkde(NULL, 0));
	ft_sace_linkde(NULL, 1);
}

void	*ft_malloc(size_t size)
{	
	void	*dest;
	t_list	*head;
	
	dest = malloc(size);
	if (dest)
	{
		head = ft_sace_linkde(NULL, 0);
		ft_lstadd_back(&head, ft_lstnew(dest));
		ft_sace_linkde(head, 1);
	}
	else 
	{
		perror("minishell");
		ft_clean_up();
		exit(1);
	}
	return (dest);
}

void ft_free(void *ptr)
{
	t_list *head;
	t_list *tmp;

	head = ft_sace_linkde(NULL, 0);
	if (!head || !ptr)
		return ;
	while (head->next->ptr != ptr)
		head = head->next;
	tmp = head->next;
	head->next = tmp->next;
	ft_lstdelone(tmp);
	ptr = NULL;
}
