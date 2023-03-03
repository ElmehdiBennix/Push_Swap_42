/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bennix <bennix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/02 17:10:50 by bennix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void exitmsg(int err)
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
            exitmsg(1);
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
                exitmsg(2);
        }
        if (allowed == 0)
            exitmsg(3);
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
                        exitmsg(4);
                    tmp++;
                }
                else if (*tmp == '\0')
                    exitmsg(5);
                else if (*tmp == ' ')
                    exitmsg(6);
                else if (*tmp == '+' || *tmp == '-')
                    exitmsg(7);
            }
            else if (*tmp == '-')
            {
                tmp++;
                if (ft_isdigit(*tmp))
                {
                    if (allowed > 0)
                        exitmsg(8);
                    tmp++;
                }
                else if (*tmp == '\0')
                    exitmsg(9);
                else if (*tmp == ' ')
                    exitmsg(10);
                else if (*tmp == '+' || *tmp == '-')
                    exitmsg(11);
            }
        }
        printf("passed\n");
    }
}

char *add_sign(char *p) //remove zeros  signzero
{
    char sign;
    if (*p && *p == ' ')
        while (*p && *p == ' ')
            p++;
    if (*p == '-')
    {
        sign = '-';
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
        sign = '+';
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
    return (ft_strjoin(&sign,p));
}

char *joinning(int ac , char **av)
{
    int i;
    char *p;
    char *str1;
    i = 1;

    while (*(++av) && ac > i)
    {
        p = add_sign(*av);
        if (i == 1)
            str1 = ft_strdup(p);
        else
        {
            str1 = ft_strjoin(str1 , "  "); // adding 2 spaces to seperate incase ;)
            str1 = ft_strjoin(str1 , p); // tmp to free leaks hir
        }
        i++;
    }
    printf("%s\n\n",str1);
    return (str1);
    return (p);
}

void push_swap(int ac, char **av)
{
    char **spl;
    char *str2;


    parsing (av); // if it passed means arguments are valid
    char *res = joinning(ac, av); //joinning for the split
    spl = ft_split(res , ' ');
    while (*spl)
    {
        str2 = *spl;
        while (*(++spl))
        {
            if (ft_strncmp(str2,*spl,ft_strlen(str2)) == 0)
                exitmsg(1);
        }
        spl++;
    }
    
}

int main (int ac, char **av)
{
    if (ac == 1)
        exitmsg(1);
    push_swap(ac,av);
    // ++av
    // printf("%s",++av);
}

// split them atoi
// check for dubs and int max and int min with strcmp after split
