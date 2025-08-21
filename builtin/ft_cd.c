/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:53:35 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/21 22:11:53 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_update_env(char *cwd)
{
	char	*pwd;
	char	*var;

	if (ft_search_env_addr("PWD"))
	{
		var = ft_strdup("OLDPWD");
		if (!var)
			return (free(cwd), ft_expend_malloc_faild());
		ft_creat_or_update_env(var, cwd);
	}
	else
		free(cwd);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_status(1), perror("minishell"));
	var = ft_strdup("PWD");
	if (!var)
		return (free(pwd), ft_expend_malloc_faild());
	ft_creat_or_update_env(var, pwd);
	ft_status(0);
}

void	ft_cd(t_exec *execute)
{
	char	*dest;
	char	*cwd;

	if (ft_lengh_of_table(execute->args) > 2)
		return (ft_status(1), (void)ft_putstr_fd(CDTMA_ERROR, 2));
	cwd = getcwd(NULL, 0);
	if (!(execute->args[1]))
	{
		dest = ft_search_expend("HOME", ft_strlen("HOME"));
		if (!dest)
			return (free(cwd), ft_status(1), (void)ft_putstr_fd(CD_HOME_ERROR,
					2));
		if (chdir(dest))
			return (free(cwd), ft_status(1), perror("minishell"));
	}
	else if (chdir(execute->args[1]))
		return (ft_status(1), free(cwd), perror("minishell"));
	if (!cwd)
		perror("minishell");
	ft_update_env(cwd);
}
