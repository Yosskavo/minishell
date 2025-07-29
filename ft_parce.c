/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/25 03:35:01 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_setup_before_heredoc(t_mini *mini)
{
	t_parce	*tmp;

	tmp = mini->start;
	while (tmp)
	{
		tmp->mini = mini;
		tmp = tmp->next;
	}
}

int	ft_parcing(t_mini *mini)
{
	if (ft_spliting(mini->str, &(mini->start)) == -1)
		return (-1);
	if (ft_tokenization(mini->start) == -1)
		return (ft_clear_list(&(mini->start)), -1);
	ft_setup_before_heredoc(mini);
	if (ft_heredoc(mini->start))
		return (ft_clear_list(&(mini->start)), -1);
	// if (ft_expantion(mini->start) == -1)
	// 	return (ft_clear_list(&mini->start), -1);
	ft_print_it(mini);
	ft_clear_list(&(mini->start));
	return (0);
}
