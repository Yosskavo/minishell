/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/02 23:22:55 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_parcing(t_mini *mini)
{
	if (ft_spliting(mini->str, &(mini->start)) == -1)
		return (-1);
	if (ft_tokenization(mini->start) == -1)
		return (ft_clear_list(&(mini->start)), -1);
	if (ft_heredoc(mini->start))
		return (ft_clear_list(&(mini->start)), -1);
	ft_expention(mini);
	ft_delete_qots(mini->start);
	ft_print_it(mini);
	ft_clear_linked(&(mini->start));
	mini->start = NULL;
	return (0);
}
