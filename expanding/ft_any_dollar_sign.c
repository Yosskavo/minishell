/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any_dollar_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 06:17:52 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 06:18:03 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_any_dolar_sign_help(char *str, int *i)
{
	(*i)++;
	while (str[(*i)++] != '\'')
		;
}

int	ft_any_dolar_sign(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (!flag && str[i] == '\'')
			ft_any_dolar_sign_help(str, &i);
		if (str[i] == '"')
		{
			flag = flag ^ 1;
			i++;
		}
		if (!str[i])
			break ;
		if (str[i] == '$' && str[i + 1] == '$')
			i += 2;
		if (str[i] == '$' && ft_valid_expention(str[i + 1]) == 2)
			return (i + 1);
		i++;
	}
	return (0);
}
