/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/02 02:36:26 by ebennix          ###   ########.fr       */
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

char *splitting(int ac , char **av)
{
    int i;
    char *str1;

    char *p;

    i = 1;
    printf("\n splitting : %d \n",ac);
    while (*(++av) && ac > i)
    {
        printf("\n *** ac : %d > i : %d \n \n",ac,i);
        p = *av;
        printf("--pinter %s \n",p);
        if (i == 1)
            str1 = ft_strdup(p);
        else
        {
            str1 = ft_strjoin(str1 , "  "); // adding 2 spaces to seperate incase ;)
            str1 = ft_strjoin(str1 , p); // tmp to free leaks hir
        }
        printf("%s \n",str1);
        i++;
    }
    return (str1);

}

void push_swap(int ac, char **av)
{
    char *res;
    printf("%d\n \n",ac);
    parsing(av); // if it passed means arguments are valid
    res = splitting(ac, av);
}

int main (int ac, char **av)
{
    if (ac == 1)
        exitmsg(1);
    push_swap(ac,av);
    // ++av
    // printf("%s",++av);
}

// split them atoi  check // 00006 turn it to 6 or +00006 turn it to +6
// check for dubs and int max and int min with strcmp after split

// "       14        411   " "       45  87 9 9 11" "14   -45  65"