/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 16:15:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int push_swap(int ac, char **av)
{
    t_list *res ;

    check_valid (av); // if it passed means arguments are valid
    res = split_args(ac, av); //joinning for the split

    
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
