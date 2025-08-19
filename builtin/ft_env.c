/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:55:25 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 05:55:53 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
extern char **environ;

int ft_env(t_exec *execute)
{
    int i = 0;
    (void)execute;  // ma katst3mlch l'argument f had l function

    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
    return 0;
}
