/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:21:33 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/19 11:31:26 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_built_in(t_exec *execute)
{
	if (execute->tocken == PWD)
		return (ft_pwd());
	if (execute->tocken == ECHO)
		return (ft_echo(execute));
	// if (execute->tocken == EXPORT)
	// 	return (ft_export);
	if (execute->tocken == UNSET)
		return (ft_unset(execute));
	if (execute->tocken == CD)
		return (ft_cd());
	if (execute->tocken == EXIT)
		return (ft_exit(execute));
	if (execute->tocken == ENV)
		return (ft_env());
	(void)execute;
	printf("built in\n");
}
