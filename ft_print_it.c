/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:12:43 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/01 22:26:41 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_write(int fd)
{
	char	c;

	while (read(fd, &c, 1))
	{
		if (c == '\n')
			printf("\\n");
		else
			printf("%c", c);
	}
	printf("\n");
}

void	ft_print(t_parce *parce)
{
	if (!parce)
		printf(" (null)");
	while (parce)
	{
		printf(" %s ", parce->str);
		parce = parce->next;
	}
	printf("\n");
}

void	ft_print_it(t_mini *mini)
{
	t_parce	*parce;

	parce = mini->start;
	while (parce)
	{
		printf("str : %p\n", parce);
		printf("str : %s --- token : ", parce->str);
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
			printf("delemiter --> ");
		else if (parce->tocken == EXPEND)
		{
			printf("expend --> exp : %s --- map : %s --- parce :",
				parce->exp->exp, parce->exp->map);
			ft_print(parce->exp->parce);
		}
		else if (parce->tocken == FILENAME_EXPEND)
		{
			printf("filename expend --> exp : %s --- map : %s --- parce :",
				parce->exp->exp, parce->exp->map);
			ft_print(parce->exp->parce);
		}
		if (parce->tocken == DELEMITER)
		{
			ft_write(parce->fd_out);
		}
		parce = parce->next;
	}
}
