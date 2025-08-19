/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:57:22 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 05:57:44 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
int ft_export(t_exec *execute)
{
    int i = 1;

    while (execute->args[i])
    {
        char *arg = execute->args[i];
        char *equal_pos = strchr(arg, '=');

        if (equal_pos)
        {
            // Temporarily split string to get KEY and VALUE
            *equal_pos = '\0';
            char *key = arg;
            char *value = equal_pos + 1;

            if (strlen(key) == 0)
                fprintf(stderr, "export: invalid key\n");
            else
                setenv(key, value, 1);

            *equal_pos = '=';  // Restore original string
        }
        else
        {
            // No '=', just export variable name with empty value or do nothing
            fprintf(stderr, "export: invalid argument: %s\n", arg);
        }

        i++;
    }
    return 0;
}
