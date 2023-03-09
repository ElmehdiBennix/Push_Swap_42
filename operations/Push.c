/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:26:38 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/09 14:53:39 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void push(t_list **stack_a, t_list **stack_b , char stack)
{
    t_list *a = *stack_a;
    t_list *b = *stack_b;
    t_list *tmp;

    if(stack == 'a')
    {
        if(!b)
            return;
        tmp = b -> next;
        b -> next = a;
        *stack_a = b;
        *stack_b = tmp;
    }
    else if(stack == 'b')
    {
        if(!a)
            return;
        tmp = a -> next;
        a -> next = b;
        *stack_b = a;
        *stack_a = tmp;
    }
}

// int main ()
// {
//     t_list *root1 = ft_lstnew(90000);
//     ft_lstcreate_back(&root1,768);
//     ft_lstcreate_back(&root1,1);
//     ft_lstcreate_back(&root1,50);
//     t_list *root2 = NULL ;
//     // ft_lstnew(50000);
//     // ft_lstcreate_back(&root2,5479);
//     // ft_lstcreate_back(&root2,1575);
//     // ft_lstcreate_back(&root2,54356);
//     push(&root1,&root2,'b');
//     while(root1)
//     {
//         printf("stack a :");
//         printf("%d\n",root1->content);
//         root1 = root1 -> next;
//     }
//     printf("----------------------------------\n");
//     while(root2)
//     {
//         printf("stack b :");
//         printf("%d\n",root2->content);
//         root2 = root2 -> next;
//     }
//     printf("----------------------------------\n");

// }
