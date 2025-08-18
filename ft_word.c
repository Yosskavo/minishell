/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:16:24 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 16:46:27 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_qots_end(char *str, int *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i] != c)
	{
		if (!str[*i])
			return (ft_puterror(c), -1);
		(*i)++;
	}
	(*i)++;
	return (0);
}

static int	ft_check_any_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (ft_qots_end(str, &i) == -1)
				return (-1);
		}
		else
			i++;
	}
	return (0);
}

static int	ft_tell_space(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		&& !(str[i] == '|' || str[i] == '>' || str[i] == '<'))
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			c = str[i];
			i++;
			while (str[i] != c)
				i++;
			i++;
		}
		else
			i++;
	}
	return (i);
}

int	ft_word(t_parce **parce, char *s, int *pos)
{
	char	*dest;
	int		i;
	int		size;

	if (ft_check_any_string(s + *(pos)) == -1)
		return (ft_status(1), -1);
	size = ft_tell_space(s + *(pos));
	dest = malloc(size + 1);
	if (!dest)
		ft_malloc_faild();
	i = 0;
	while (i < size)
	{
		dest[i] = s[*pos + i];
		i++;
	}
	dest[i] = '\0';
	(*pos) += size;
	if (!ft_list_add_back(parce, ft_newlist(dest)))
		ft_malloc_faild();
	return (0);
}
