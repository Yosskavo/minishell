/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:20:19 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/11 05:50:27 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_execute(t_mini *mini)
{
	// if (!(mini->execute->next) && mini->execute->cmd->tocken == BUILT_IN)
	// 	return (ft_before_built_in(mini->execute));
	// else
	return (ft_before_forking(mini->execute));
}
