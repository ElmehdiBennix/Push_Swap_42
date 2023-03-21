/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:24:47 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/21 18:25:36 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../push_swap.h"

// void sort_four(int size, t_list **stack_a, t_list **stack_b)
// {
//     t_list *arrow = *stack_a;

//     while(arrow -> position != 0)
//         arrow = arrow -> next;
//     if (arrow -> index == 0 || arrow -> index == 1)
//     {
//         if(arrow -> index == 1)
//             rotate(stack_a,'a');
//         push(stack_a,stack_b,'b');
//         init_position(*stack_a); // make it dont last just a copy of positon
//         sort_under_five(size - 1,stack_a,stack_b);
//         push(stack_a,stack_b,'a');
//         init_position(*stack_a);
//     }
//     else
//     {
//         while ((*stack_a) -> position != 0)
//             reverse_rotate(stack_a,'a');
//         push(stack_a,stack_b,'b');
//         init_position(*stack_a); // make it dont last just a copy of positon
//         sort_under_five(size - 1,stack_a,stack_b);
//         push(stack_a,stack_b,'a');
//         init_position(*stack_a);
//     }
// }

// void sort_five(int size, t_list **stack_a, t_list **stack_b)
// {
//     t_list *arrow = *stack_a;
//     t_list *tmp = *stack_a;
//     while(arrow -> position != 0)
//     {
//         while(tmp -> position != 1)
//             tmp = tmp -> next;
//         arrow = arrow -> next;
//     }
//     if (arrow -> index == 0 || arrow -> index == 1)
//     {
//         while ((*stack_a) -> position != 0)
//             rotate(stack_a,'a');
//         push(stack_a,stack_b,'b');
//         while ((*stack_a) -> position != 1)
//             rotate(stack_a,'a');
//         push(stack_a,stack_b,'b');
//         init_position(*stack_a); // make it dont last just a copy of positon
//         sort_under_five(size - 2,stack_a,stack_b);
//         push(stack_a,stack_b,'a');
//         push(stack_a,stack_b,'a');
//         init_position(*stack_a);
//     }
//     else
//     {
//         while ((*stack_a) -> position != 0)
//             reverse_rotate(stack_a,'a');
//         push(stack_a,stack_b,'b');
//         while ((*stack_a) -> position != 1)
//             reverse_rotate(stack_a,'a');
//         push(stack_a,stack_b,'b');    
//         init_position(*stack_a); // make it dont last just a copy of positon
//         sort_under_five(size - 2,stack_a,stack_b);
//         push(stack_a,stack_b,'a');
//         push(stack_a,stack_b,'a');
//         init_position(*stack_a);
//     }
// }

void sort_under_five(int size, t_list **stack_a, t_list **stack_b)
{
    t_list *arrow = *stack_a;
    
    if (size == 1)
        return;
    else if (size == 2 && arrow -> content > arrow -> next -> content)
        swap(stack_a, stack_b, 'a');
    else if (size == 3)
    {
        if(arrow -> position == 1 && arrow -> next -> position == 0)
            swap(stack_a, stack_b, 'a');
        else if (arrow -> position == 2 && arrow -> next -> position == 1)
        {
            swap(stack_a, stack_b,'a');
            reverse_rotate(stack_a, stack_b,'a');
        }
        else if (arrow -> position == 2 && arrow -> next -> position == 0)
            rotate(stack_a, stack_b,'a');
        else if(arrow -> position == 0 && arrow -> next -> position == 2)
        {
            swap(stack_a, stack_b,'a');
            rotate(stack_a, stack_b, 'a');
        }
        else if(arrow -> position == 1 && arrow -> next -> position == 2)
            reverse_rotate(stack_a, stack_b,'a'); // print the a'' in function recusive too
    }
    else if (size == 4)
    {
        while(arrow -> position != 0)
            arrow = arrow -> next;
        if (arrow -> index == 0 || arrow -> index == 1)
        {
            if(arrow -> index == 1)
                rotate(stack_a, stack_b,'a');
            push(stack_a,stack_b,'b');
            init_position(*stack_a); // make it dont last just a copy of positon
            sort_under_five(size - 1,stack_a,stack_b);
            push(stack_a,stack_b,'a');
            init_position(*stack_a);
        }
        else
        {
            while ((*stack_a) -> position != 0)
                reverse_rotate(stack_a, stack_b,'a');
            push(stack_a,stack_b,'b');
            init_position(*stack_a); // make it dont last just a copy of positon
            sort_under_five(size - 1,stack_a,stack_b);
            push(stack_a,stack_b,'a');
            init_position(*stack_a);
        }
    }
    else if (size == 5)
    {
        t_list *tmp = *stack_a;
        while(arrow -> position != 0)
        {
            while(tmp -> position != 1)
                tmp = tmp -> next;
            arrow = arrow -> next;
        }
        if (arrow -> index == 0 || arrow -> index == 1)
        {
            while ((*stack_a) -> position != 0)
                rotate(stack_a, stack_b,'a');
            push(stack_a,stack_b,'b');
            while ((*stack_a) -> position != 1)
                rotate(stack_a, stack_b,'a');
            push(stack_a,stack_b,'b');
            init_position(*stack_a); // make it dont last just a copy of positon
            sort_under_five(size - 2,stack_a,stack_b);
            push(stack_a,stack_b,'a');
            push(stack_a,stack_b,'a');
            init_position(*stack_a);
        }
        else
        {
            while ((*stack_a) -> position != 0)
                reverse_rotate(stack_a, stack_b,'a');
            push(stack_a,stack_b,'b');
            while ((*stack_a) -> position != 1)
                reverse_rotate(stack_a, stack_b,'a');
            push(stack_a,stack_b,'b');    
            init_position(*stack_a); // make it dont last just a copy of positon
            sort_under_five(size - 2,stack_a,stack_b);
            push(stack_a,stack_b,'a');
            push(stack_a,stack_b,'a');
            init_position(*stack_a);
        }
        // while ((*stack_a) -> position != 0)
        // {
        //     if(get_index(*stack_a,(*stack_a) -> position) <= 3)
        //         rotate(stack_a,'a');
        //     else
        //         reverse_rotate(stack_a,'a');
        // }
        // push(stack_a,stack_b,'b');
        // while ((*stack_a) -> position != 1)
        // {
        //     if(get_index(*stack_a,(*stack_a) -> position) <= 3)
        //         rotate(stack_a,'a');
        //     else
        //         reverse_rotate(stack_a,'a');
        // }
    }
}