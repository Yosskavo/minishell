/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:18:19 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/23 23:18:26 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_built_in(t_exec *execute)
{
	if (execute->tocken == PWD)
		return (ft_pwd());
	if (execute->tocken == ECHO)
		return (ft_echo(execute));
	if (execute->tocken == EXPORT)
		return (ft_export(execute));
	if (execute->tocken == UNSET)
		return (ft_unset(execute));
	if (execute->tocken == CD)
		return (ft_cd(execute));
	if (execute->tocken == EXIT)
		return (ft_exit(execute));
	if (execute->tocken == ENV)
		return (ft_env());
}
