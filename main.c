/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:50:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/04 05:16:07 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *add_sign(char *p) //remove zeros  signzero
{
    char *sign = NULL;

    if (*p && *p == ' ')
        while (*p && *p == ' ')
            p++;
    if (*p && *p == '-')
    {
        sign = "-";
        p++;
        while (*p)
        {
            if (*p == '0')
            {
                p++;
                if (*p == '\0')
                    return (ft_strdup(--p));
            }
            else
                break;
        }
    }
    else if (*p && (*p == '+' || ft_isdigit(*p)))
    {
        sign = "+";
        if (*p == '+')
            p++;
        while (*p)
        {
            if (*p == '0')
            {
                p++;
                if (*p == '\0')
                    return (ft_strdup(--p));
            }
            else
                break;
        }
    }
    return (ft_strjoin(sign,p));
}

int main (int ac , char **av)
{
    char *p;
    (void)ac;
    
    while (*(++av))
    {
        p = add_sign(*av);
        printf("%s\n",p);    
    }
}