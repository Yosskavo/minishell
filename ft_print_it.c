/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:12:43 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 13:25:28 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"


void ft_write(int fd)
{
	char *str;

	while ((str = get_next_line(fd)) != NULL)
	{
		printf ("%s", str);
		free(str);
	}
}


void	ft_print_it(t_mini *mini)
{
	t_parce	*parce;

	parce = mini->start;
	while (parce)
	{
		if (*(parce->str) == '\0')
			printf("str : empty string \n"); // if (parce->tocken == WORD)
		else
			printf("str : %s --- tocken :", parce->str);
		if (parce->tocken == WORD)
			printf("word \n");
		else if (parce->tocken == PIPE)
			printf("pipe \n");
		else if (parce->tocken == APPEND)
			printf("append \n");
		else if (parce->tocken == HEREDOC)
			printf("heredoc \n");
		else if (parce->tocken == REDIRACTION)
			printf("rediraction \n");
		else if (parce->tocken == OVERWRITE)
			printf("overwrite \n");
		else if (parce->tocken == ERROR_TOCKEN)
			printf("error\n");
		else if (parce->tocken == FILENAME)
			printf("filename\n");
		else if (parce->tocken == DELEMITER)
			printf("delemiter \n");
		if (parce->tocken == DELEMITER)
		{
			ft_write(parce->fd_out);
		}
		parce = parce->next;
	}
	// int i = 0;
	// while (mini->env[i])
	// {
	//   printf("%s\n", mini->env[i]);
	//   i++;
	// }
}
