/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 18:35:03 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_parcing(char *str, t_mini *mini)
{
	// ft_golobal_struct(mini);
	if (ft_spliting(str, &(mini->start)) == -1)
		return (-1);
	if (ft_tokenization(mini->start) == -1)
		return (ft_clear_list(&(mini->start)), -1);
	if (ft_heredoc(mini->start))
	return (ft_clear_list(&(mini->start)), -1);	
	ft_print_it(mini);
	// ft_expanding(parce);
	// ft_excuting(mini);
	ft_clear_list(&(mini->start));
	return (0);
}
