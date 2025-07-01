/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:16:24 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/01 13:47:32 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int ft_qots_end(char *str, int *i)
{
	char c;
	int	flag;
	
	c = str[*i];
	if (c == '\"')
		flag = 2;
	else 
		flag = 1;
	(*i)++;
	while (str[*i] != c)
	{
		if (!str[*i])
			return (ft_puterror(flag), -1);
		(*i)++;
	}
	(*i)++;
	return (0);
}

static void ft_cpy_str_word(char *dest, char *s, int *pos, int *i)
{
	int size;
	int	count;
	
	size = 0;
	ft_qots_end(s + *(pos), &size);
	count = 0;
	while (count < size)
	{
		dest[*i] = s[*pos];
		(*pos)++;
		(*i)++;
		count++;
	}
}

static int ft_check_any_string(char *str)
{
	int i;

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

static int ft_tell_space(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
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

int ft_word(t_parce **parce, char *s, int *pos)
{
	char *dest;
	int		i;

	if (ft_check_any_string(s + *(pos)) == -1)
		return (-1);
	int tmp = ft_tell_space(s + (*pos));
	dest = malloc(tmp + 1);
	if (!dest)
		return (ft_puterror(0), -1);
	i = 0;
	while (s[*pos] && !(s[*pos] == ' ' || (s[*pos] >= 9 && s[*pos] <= 13)))
	{
		if (s[*pos] == '\"' || s[*pos] == '\'')
			ft_cpy_str_word(dest, s, pos, &i);
		else
		{
			dest[i] = s[*pos];
			i++;
			(*pos)++;
		}
	}
	dest[i] = '\0';
	if (!ft_list_add_back(parce, ft_newlist(dest)))
		return (ft_puterror(0), -1);
	return (0);
}
