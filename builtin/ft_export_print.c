/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:44:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/21 23:30:56 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static char	**ft_sort_table(char **table)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (table[++i])
	{
		j = i;
		while (table[j])
		{
			if (ft_strcmp(table[i], table[j]) < 0)
			{
				tmp = table[j];
				table[j] = table[i];
				table[i] = tmp;
				i = -1;
				break ;
			}
			j++;
		}
	}
	return (table);
}

static char	**ft_env_table_sort(t_env *env)
{
	char	**table;
	int		i;

	i = ft_listsize_env();
	table = malloc(sizeof(char *) * (i + 1));
	if (!table)
		ft_expend_malloc_faild();
	i = 0;
	while (env)
	{
		if (!(env->value))
			table[i] = ft_strdup(env->variable);
		else
			table[i] = ft_strcjoin(env->variable, env->value, '=');
		if (!table[i])
			return (ft_freetable(table), ft_expend_malloc_faild(), NULL);
		env = env->next;
		i++;
	}
	table[i] = NULL;
	return (ft_sort_table(table));
}

void	ft_export_print_it(void)
{
	t_env	*env;
	int		i;
	char	**table;

	env = ft_global(NULL)->env;
	if (!env)
		return ((void)ft_status(1));
	table = ft_env_table_sort(env);
	i = 0;
	while (table[i])
	{
		printf("%s %s\n", DECLEAR, table[i]);
		i++;
	}
	ft_freetable(table);
	ft_status(0);
}
