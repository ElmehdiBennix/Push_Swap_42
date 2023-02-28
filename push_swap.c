/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bennix <bennix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/28 16:46:29 by bennix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main (int ac, char **av)
{
    printf("%d\n",ac);

    char *tmp;
    int err = 0;
    int i;
    int totaldig = 0;


    while (*(++av))
    {
        tmp = *av;
        if (*tmp == '\0')
            err++;
        while (*tmp != '\0')
        {
            i = 0;
            while (*tmp == ' ')
            {
                tmp++;
                if(*tmp == '\0' && totaldig == 0)
                    err++;
            }
            if (ft_isdigit(*tmp))
            {
                while (ft_isdigit(*tmp))
                {
                        i++;
                        totaldig++;
                        tmp++;
                }
                printf("i = %d and totaldig = %d\n",i,totaldig);
            }
            else if (*tmp == '+')
            {
                tmp++;
                if(ft_isdigit(*tmp))
                {
                    while (ft_isdigit(*tmp) && i > 0)
                        err++;
                }
                if (*tmp ==  '\0')
                    err++;
                if (*tmp == ' ')
                    err++;
                else if (*tmp == '+' || *tmp == '-')
                    err++;

            }
            else if (*tmp == '-')
            {
                tmp++;
                if(ft_isdigit(*tmp))
                {
                    while (i > 0 && ft_isdigit(*tmp) == 1)
                    {
                        printf("\n -entered :\n");
                        err++;
                    }
                }
                if (*tmp ==  '\0')
                    err++;
                if (*tmp == ' ')
                    err++;
                else if (*tmp == '+' || *tmp == '-')
                    err++;
            }
            
        }
        printf("\n -error counter : %d\n",err);
    }
    // bennix@MehdiPC ~/myProjects/Push_swap42$ ./a.out  "    +-455  41+455     "                                                                                                                                 ✹main 
        
}