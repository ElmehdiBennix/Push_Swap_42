/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/10 17:55:02 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void position_sort()
{

}

void sort_under_five(int size, t_list *stack_a, t_list *stack_b)
{
    if (size == 1)
        return;
    else if (size == 2 && stack_a -> content > stack_a -> next -> content)
        swap(&stack_a, 'a');
    else if (size == 3)
    {

    }
}

int push_swap(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;
    int size = ac - 1;

    check_valid (av); // if it passed means arguments are valid
    stack_a = split_args(ac, av); //joinning for the split
    stack_b = NULL;
    sort_under_five(size,stack_a,stack_b);
    
    t_list *arrow = stack_a;

    printf("\n");
    while(arrow)
    {
        printf("%d\n",arrow -> content);
        arrow = arrow -> next;
    }
    printf("\nsorted :/\n");
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
