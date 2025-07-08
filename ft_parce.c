/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/07 12:59:20 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_parcing(char *str, t_mini *mini)
{
	mini->start = NULL;
	if (ft_spliting(str, &(mini->start)) == -1)
		return (-1);
	// ft_print_it(parce);
	ft_tokenization(mini->start);
  ft_print_it(mini);
	// ft_expanding(parce);
	ft_clear_list(&(mini->start));
	return (0);
}
