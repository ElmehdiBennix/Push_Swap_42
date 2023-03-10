/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:26:41 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/10 17:43:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void reverse_rotate(t_list **stack, char AorB)
{
    t_list *tmp = *stack;
    t_list *second_last = NULL;
    
    while (tmp -> next != NULL) 
    {
        second_last = tmp;
        tmp = tmp -> next;
    }
    second_last -> next = NULL;
    ft_lstadd_front(stack,tmp);
    if(AorB == 'a')
        write(1,"rra\n",5);
    else if (AorB == 'b')
        write(1,"rrb\n",5);
    else
        return;
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a,'r');
    reverse_rotate(stack_b,'r');
    write(1,"rrr\n",5);

}

// int main ()
// {
//     t_list *root1 = ft_lstnew(90000);
//     ft_lstcreate_back(&root1,768);
//     ft_lstcreate_back(&root1,1);
//     ft_lstcreate_back(&root1,50);
//     t_list *root2 = ft_lstnew(50000);
//     ft_lstcreate_back(&root2,5479);
//     ft_lstcreate_back(&root2,1575);
//     ft_lstcreate_back(&root2,54356);
//     rrr(&root1,&root2);
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