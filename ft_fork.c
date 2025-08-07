/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:26:41 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/06 21:43:45 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_before_forking(t_exec *execute)
{
	if (execute->next || execute->redi)
		ft_save_original_fd();
	while (execute)
	{
	}
}
