/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:54:32 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 05:55:00 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_echo(t_exec *execute)
{
    int i = 1;
    int newline = 1;

    // Check for multiple -n options (e.g. echo -n -n hello)
    while (execute->args[i] && strcmp(execute->args[i], "-n") == 0)
    {
        newline = 0;
        i++;
    }

    while (execute->args[i])
    {
        printf("%s", execute->args[i]);
        if (execute->args[i + 1])
            printf(" ");
        i++;
    }

    if (newline)
        printf("\n");

    return 0;
}
