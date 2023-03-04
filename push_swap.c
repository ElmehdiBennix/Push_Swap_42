/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/04 08:04:42 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void failure(int err)
{
    write(2,"Error\n",7);
    exit(err);
}

void parsing(char **av)
{
    char *tmp;
    size_t allowed;

    while (*(++av))
    {
        tmp = *av;
        allowed = 0;
        if (*tmp == '\0')
            failure(1);
        while (*tmp != '\0')
        {
            if (*tmp == ' ') 
                tmp++;
            else if(ft_isdigit(*tmp) || *tmp == '+' || *tmp == '-')
            {
                allowed++;
                tmp++;
            }
            else
                failure(2);
        }
        if (allowed == 0)
            failure(3);
        tmp = *av;
        while (*tmp != '\0')
        {
            allowed = 0;
            while (*tmp == ' ')
                tmp++;
            while (ft_isdigit(*tmp))
            {
                allowed++;
                tmp++;
            }
            if (*tmp == '+')
            {
                 tmp++;
                if (ft_isdigit(*tmp))
                {
                    if (allowed > 0)
                        failure(4);
                    tmp++;
                }
                else if (*tmp == '\0')
                    failure(5);
                else if (*tmp == ' ')
                    failure(6);
                else if (*tmp == '+' || *tmp == '-')
                    failure(7);
            }
            else if (*tmp == '-')
            {
                tmp++;
                if (ft_isdigit(*tmp))
                {
                    if (allowed > 0)
                        failure(8);
                    tmp++;
                }
                else if (*tmp == '\0')
                    failure(9);
                else if (*tmp == ' ')
                    failure(10);
                else if (*tmp == '+' || *tmp == '-')
                    failure(11);
            }
        }
    }
}

char *sign_zero(char *p) //remove zeros  signzero
{
    char *sign = NULL;

    if (*p && *p == ' ')
        while (*p && *p == ' ')
            p++;
    if (*p == '-')
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
    else if (*p == '+' || ft_isdigit(*p))
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

char **joinning(int ac , char **av)
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

    printf("\n");
    save = res;
    while (*res)
    {
        *res = sign_zero(*res);
        printf("%s ",*res);
        res++;
        i++;
    }
    printf("\n\n");
    res = save;
    while (*res)
    {
        p = res;
        while(*(++p))
            if (ft_strncmp(*res,*p,ft_strlen(*res)) == 0 && ft_strncmp(*res,*p,ft_strlen(*p)) == 0)
                failure(1);
        res++;
        i++;
    }
    res = save;
    return (res);
}

int push_swap(int ac, char **av)
{
    char **res ;


    parsing (av); // if it passed means arguments are valid
    res = joinning(ac, av); //joinning for the split

    return (0);
}

int main (int ac, char **av)
{
    int err;
    
    if (ac == 1)
        failure(1);
    err = push_swap(ac,av);
    
    return (err);
}


// split them atoi
// atoi then check for max min int in linked list loop
        // if (ft_strncmp(*res,"+2147483647",12) == 0)
        //         exitmsg(1);
        // if (ft_strncmp(*res,"-2147483648",12) == 0)   
        //         exitmsg(1);