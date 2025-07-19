/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:24:37 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/16 21:29:55 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_list	*ft_save_linkde(t_list *new, int i)
{
	static t_list *head;
	static t_list *head_env;

	if (!i)
	{
		head = new;
	}
	else if (i == 1)
	{
		head_env = new;
	}
	if (!i || i == 2)
		return (head);
	return (head_env);
}

void ft_clean_up(void)
{
	t_list *head;

	head = ft_save_linkde(NULL, 1);
	ft_lstclear(&head);
	ft_save_linkde(NULL, 1);
}

void	*ft_malloc(size_t size, int flag)
{	
	void	*dest;
	t_list	*head;
	
	dest = malloc(size);
	if (dest)
	{
		head = ft_save_linkde(NULL, flag);
		ft_lstadd_back(&head, ft_lstnew(dest));
		ft_save_linkde(head, 1);
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

	head = ft_save_linkde(NULL, 0);
	if (!head || !ptr)
		return ;
	while (head->next->ptr != ptr)
		head = head->next;
	tmp = head->next;
	head->next = tmp->next;
	ft_lstdelone(tmp);
	ptr = NULL;
}
