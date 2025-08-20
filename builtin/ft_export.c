/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:57:22 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/20 14:59:18 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_export_valid_expention(char c)
{
	if (c == '_' || ft_isalpha(c))
		return (1);
	if (ft_isalnum(c))
		return (2);
	return (0);
}

static int	ft_var_check(char *str)
{
	int	i;

	i = 0;
	if (!str[0] || ft_export_valid_expention(str[0]) != 1)
		return (-1);
	if (str[i] != '=')
	{
		if (!ft_export_valid_expention(str[i]))
			return (-1);
		if (!str[i])
			return (-2);
		i++;
	}
	return (0);
}
static int	ft_export_check_name(char *str, int *i)
{
	char	*var;
	char	*val;
	t_env	*env;
	int		flag;

	flag = ft_var_check(str);
	if (flag == -1)
		return (ft_export_error(str), -1);
	if (flag == -2)
	{
	}
}

void	ft_export(t_exec *execute)
{
	int		i;
	int		j;
	int		flag;
	char	*pos;

	flag = 0;
	if (!(execute->args[1]))
		return (ft_export_print_it());
	i = 1;
	while (execute->args[i])
	{
		j = 0;
		if (ft_export_check_name(execute->args[i], &j) == -1)
		{
			i++;
			flag = 1;
			continue ;
		}
		ft_export_add_to_env(execute->args[i], &j);
		i++;
	}
	ft_status(flag);
}
