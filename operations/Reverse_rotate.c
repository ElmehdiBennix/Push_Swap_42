/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:26:41 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/12 23:23:12 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void reverse_rotate(t_list **stack, char AorB)
{
    t_list *arrow = *stack;
    t_list *second_last = NULL;
    
    while (arrow -> next != NULL) 
    {
        second_last = arrow;
        arrow = arrow -> next;
    }
    second_last -> next = NULL;
    // printf("arrow : %d \n", arrow -> content);
    // printf("arrow : %p \n\n", arrow -> next);
    // printf("second last : %d \n", arrow -> content);
    // printf("second last : %p \n\n", arrow -> next);
    ft_lstadd_front(stack,arrow);
    if(AorB == 'a')
        write(1,"rra\n",5);
    else if (AorB == 'b')
        write(1,"rrb\n",5);
    else if (AorB == 'r')
        write(1,"rrr\n",5);
;
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a,'r');
    reverse_rotate(stack_b,'r');
}

// int main ()
// {
//     t_list *root1 = ft_lstnew(90000);
//     ft_lstcreate_back(&root1,768);
//     ft_lstcreate_back(&root1,1);
//     ft_lstcreate_back(&root1,50);
//     // t_list *root2 = ft_lstnew(50000);
//     // ft_lstcreate_back(&root2,5479);
//     // ft_lstcreate_back(&root2,1575);
//     // ft_lstcreate_back(&root2,54356);
//     reverse_rotate(&root1,'a');
//     while(root1)
//     {
//         printf("stack a :");
//         printf("%d and p = %p \n",root1->content,root1->next);
//         root1 = root1 -> next;
//     }
//     printf("----------------------------------\n");
//     // while(root2)
//     // {
//     //     printf("stack b :");
//     //     printf("%d\n",root2->content);
//     //     root2 = root2 -> next;
//     // }
//     // printf("----------------------------------\n");
// }