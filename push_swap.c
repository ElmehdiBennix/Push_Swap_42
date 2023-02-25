/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/25 17:10:41 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main (int ac, char **av)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (av[j])
    {
        while (*av[i] != '\0')
        {
            while (*av[i] == ' ')
                i++;
            if (ft_isdigit(*av[i]) == 1)
                while(ft_isdigit(*av[i]))
                        i++;
            else if (*av[i] == '-')
            {
                i++;
                if (ft_isdigit(*av[i]))
                    while(ft_isdigit(*av[i]))
                        i++;
                else
                    write(2,"error\n",7);
            }
            else
                write(2,"error\n",7);
        }
        j++;
    }
    // if(ft_isdigit(*av) == 1)
    //     printf("2 is %c\n",s); // ok we check on all args if they are digit first then we continue
        
}