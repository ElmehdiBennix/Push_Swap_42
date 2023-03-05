/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:59:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 10:04:35 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

char **split_args(int ac , char **av)
{
    int i;
    char *str;
    char **res;
    char **save;
    char **p;

    i = 1;
    while (*(++av) && ac > i)
    {
        if (i == 1)
            str = ft_strdup(*av);
        else
        {
            str = ft_strjoin(str , " "); // adding 2 spaces to seperate incase ;)
            str = ft_strjoin(str , *av); // tmp to free leaks hir
        }
        i++;
    }
    res = ft_split(str , ' ');
    save = res;
    while (*res)
    {
        *res = sign_zero(*res);
        res++;
    }
    res = save;
    while (*res)
    {
        p = res;
        while(*(++p))
            if (ft_strncmp(*res,*p,ft_strlen(*res)) == 0 && ft_strncmp(*res,*p,ft_strlen(*p)) == 0)
                failure(12);
        res++;
    }
    res = save;
    return (res);
}