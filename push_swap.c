/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 09:03:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void failure(int err)
{
    write(2,"Error\n",7);
    exit(err);
}

void check_valid(char **av) // check for valid arguments
{
    char *tmp;
    unsigned int allowed;

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

char *sign_zero(char *p) //remove zeros and add signs
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

int push_swap(int ac, char **av)
{
    char **res ;

    check_valid (av); // if it passed means arguments are valid
    res = joinning(ac, av); //joinning for the split

    t_list *root = ft_lstnew(ft_atoi(*res));
    while(*(++res))
        ft_lstcreate_back(&root,ft_atoi(*res));
    t_list *arrow = root;
    while (arrow)
    {
        printf("%d\n",arrow -> content);
        arrow = arrow -> next;
    }
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
