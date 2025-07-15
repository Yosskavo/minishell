/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:20:37 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 22:36:57 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void *ptr;
	struct s_list *next;
}	t_list;

void	*ft_malloc(size_t size);
void ft_clean_up(void);
t_list	*ft_save_linkde(t_list *new, int i);
void ft_free(void *ptr);
void ft_lstadd_back(t_list **head, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
#endif
