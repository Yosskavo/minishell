/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qotes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:49:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/28 12:51:11 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_edge_qot_case(char *str)
{
	int	i;
	int cont_sq;
	int cont_dq;

	while (str[i])
	{
		if (str[i] == '\'')
		{
			cont_sq++;
			while (str[i] != '\'' && str[i])
				i++;
			cont_sq++;
		}
		else if (str[i] == '\"')
		{
			cont_dq++;
			while (str[i] != '\"' && str[i])
				i++;
			cont_sq++;
		}
		if (!str[i])
			return (-1);
		i++;
	}
	if (cont_dq % 2 != 0)
		return (ft_puterror(1, '\"'));
	if (cont_dq % 2 != 0)
		return (ft_puterror(1, '\''));
} 

int	ft_qots_error(char *str)
{
	char	c;
	int		i;

	if (*str == '\"')
		c = '\"';
	else
		c = '\'';
	i = 1;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_tell_next_qot(char *str)
{
	int i;
	char c;

	if (*str == '\"')
		c = '\"';
	else
		c = '\'';
	i = 1;
	while (str[i] != c)
		i++;
	return (i + 1);
}

char *ft_cpy_tell_qot(char *str)
{
	char *dest;
	int	size;
	char	c;
	int		i;

	size = ft_tell_next_qot(str);
	dest = malloc(size + 1);
	if (!dest)
		return (0);
	if (*str == '\"')
		c = '\"';
	else
		c = '\'';
	i = 0;
	while (i - 1 < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_qots_handle(t_parce **lst, char *str)
{
	char *dest;

	if (!ft_qots_error(str))
		return (ft_puterror(1, *str));
	dest = ft_cpy_tell_qot(str);
	if (!dest)
		return (ft_puterror(0, '\0'));
	ft_list_add_back(lst, ft_newlist(dest));
	return (1);
}
