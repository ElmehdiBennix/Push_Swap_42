/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:18:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/21 18:23:30 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../push_swap.h"

void init_index(t_list *stack)
{
    t_list *arrow = stack;

    int i = 0;
    while (arrow)
    {
        arrow -> index = i++;
        arrow = arrow -> next;
    }
}

void init_position(t_list *stack)
{
    t_list *arrow = stack;
	t_list	*p;
    while (arrow)
    {
        arrow -> position = 0;
        arrow = arrow -> next; // could get it inside the while loop
    }    

	arrow = stack;
	while (arrow)
	{
        // arrow -> position = 0;
		p = stack;
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