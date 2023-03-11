/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/11 20:27:44 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void init_position(t_list *stack_a)
{
    t_list *arrow = stack_a;
	t_list	*p;
    while (arrow)
    {
        arrow -> position = 0;
        arrow = arrow -> next;
    }    

	arrow = stack_a;
	while (arrow)
	{
        // arrow -> position = 0;
		p = stack_a;
		while (p)
		{
			if (arrow -> content < p -> content)
				p -> position += 1;
			p = p -> next;
		}
		arrow = arrow -> next;
	}
    // arrow = stack_a;
    // while (arrow)
    // {
    //     printf("%d :",arrow ->content);
    //     printf(" position -> %d\n",arrow ->position);
    //     arrow = arrow ->next;
    // } 
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
    init_position(stack_a);
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
