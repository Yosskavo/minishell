/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:33:57 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 05:34:00 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_pwd(void)
{
	char	dest[PATH_MAX];

	if (!getcwd(dest, PATH_MAX))
		return (ft_status(1), perror("minishell"));
	ft_putendl_fd(dest, 1);
	ft_status(0);
}
