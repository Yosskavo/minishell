/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:57:22 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/21 02:43:39 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_export_print_it(void)
{
	t_env	*env;

	env = ft_global(NULL)->env;
	while (env)
	{
		printf("%s %s=%s\n", DECLEAR, env->variable, env->value);
		env = env->next;
	}
	ft_status(0);
}

static int	ft_export_check_name(char *str)
{
	char	*var;
	char	*val;

	val = NULL;
	var = ft_env_var(str);
	if (!var)
		ft_expend_malloc_faild();
	if (ft_var_check(var) < 0)
		return (ft_export_error(str), -1);
	if (ft_strchr(str, '='))
	{
		val = ft_env_val(str);
		if (!val)
			return (free(var), ft_expend_malloc_faild(), -1);
	}
	ft_creat_or_update_env(var, val);
	return (0);
}

void	ft_export(t_exec *execute)
{
	int	i;
	int	flag;

	flag = 0;
	if (!(execute->args[1]))
		return (ft_export_print_it());
	i = 1;
	while (execute->args[i])
	{
		if (ft_export_check_name(execute->args[i]) == -1)
			flag = 1;
		i++;
	}
	ft_status(flag);
}
