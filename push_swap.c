/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/09 18:06:48 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void under_five()
{


}
int push_swap(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;

    check_valid (av); // if it passed means arguments are valid
    stack_a = split_args(ac, av); //joinning for the split
    stack_b = NULL;
    
    
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
