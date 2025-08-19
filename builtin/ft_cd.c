/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:53:35 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 05:53:51 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
int ft_cd(t_exec *execute)
{
    char *dir = execute->args[1];
    if (!dir) {
        dir = getenv("HOME");
        if (!dir) {
            fprintf(stderr, "cd: HOME not set\n");
            return 1;
        }
    }
    printf("Changing directory to: %s\n", dir);
    if (chdir(dir) != 0) {
        perror("cd");
        return 1;
    }
    return 0;
}
