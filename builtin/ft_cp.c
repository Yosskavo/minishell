/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:53:35 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/20 03:45:25 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_update_env(void)
{
	t_env	*pwd;
	t_env	*oldpwd;

	oldpwd = ft_search_env_addr("OLDPWD");
	pwd = ft_search_env_addr("PWD");
	if (oldpwd && pwd)
	{
		free(oldpwd->value);
		oldpwd->value = pwd->value;
	}
	if (pwd)
	{
		if (!oldpwd)
			free(pwd->value);
		pwd->value = getcwd(NULL, 0);
		if (!(pwd->value))
			return (perror("minishell"), (void)ft_status(1));
	}
	ft_status(0);
}

void	ft_cd(t_exec *execute)
{
	char	*dest;

	if (ft_lengh_of_table(execute->args) > 2)
		return (ft_status(2), (void)ft_putstr_fd(CDTMA_ERROR, 2));
	if (!(execute->args[1]))
	{
		dest = ft_search_expend("HOME", ft_strlen("HOME"));
		if (!dest)
			return (ft_status(1), ft_putstr_fd(CD_HOME_ERROR, 2), (void)1);
		if (chdir(dest))
			return (ft_status(1), perror("minishell"), (void)1);
	}
	else if (chdir(execute->args[1]))
		return (ft_status(2), perror("minishell"));
	ft_update_env();
}
