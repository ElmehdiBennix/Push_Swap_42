/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/01 22:23:55 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void exitmsg(int err)
{
    write(2,"error\n",7);
    exit(err);
}
void ()
{
    
}


int main (int ac, char **av)
{
    printf("%d\n",ac);

    char *tmp;
    int allowed;

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
    // ./a.out  "    +-455  41+455     "    
    // ./a.out  "  000014   +47  -24   +-  9- 9+   --89 ++89  " 
    //  split them atoi  check // max int // min int // 00006
