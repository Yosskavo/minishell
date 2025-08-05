/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/05 22:49:44 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_parcing(t_mini *mini)
{
	if (ft_spliting(mini->str, &(mini->start)) == -1)
		return (-1);
	if (ft_tokenization(mini->start) == -1)
		return (ft_clear_list(&(mini->start)), -1);
	ft_expention(mini);
	ft_delete_qots(mini->start);
	if (ft_heredoc(mini->start))
		return (ft_clear_list(&(mini->start)), -1);
	mini->start = ft_clean_before_exec(mini->start);
	mini->execute = ft_transefarce();
	// ft_print_it(mini);
	ft_mini_clear_list(&(mini->start));
	mini->start = NULL;
	print(mini->execute);
	return (0);
}

int	ft_start(void)
{
	t_mini	*mini;

	mini = ft_global(NULL);
	if (ft_parcing(mini) == -1)
		return (-1);
	return (0);
}
