/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:31:55 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/31 18:58:20 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_spliting(char *str, t_parce **parce)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			ft_split_operator(parce, str, &i);
		else if (str[i] && ft_word(parce, str, &i) == -1)
			return (ft_clear_list(parce), -1);
	}
	return (0);
}
