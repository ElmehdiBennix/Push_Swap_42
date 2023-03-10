/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:27:05 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/10 17:43:18 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void rotate(t_list **stack, char AorB)
{
    t_list *tmp = *stack;

    *stack = (*stack) -> next;
    tmp -> next = NULL;
    
    ft_lstadd_back(stack,tmp);
    if(AorB == 'a')
        write(1,"ra\n",4);
    else if (AorB == 'b')
        write(1,"rb\n",4);
    else
        return;
}

void rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a,'r');
    rotate(stack_b,'r');
    write(1,"rr\n",4);

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
//     rr(&root1,&root2);
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

// int main ()
// {
//     t_list *root1 = ft_lstnew(90000);
//     ft_lstcreate_back(&root1,768);
//     ft_lstcreate_back(&root1,1);
//     ft_lstcreate_back(&root1,50);
//     rotate(&root1);
//     while(root1)
//     {
//         printf("stack a :");
//         printf("%d\n",root1->content);
//         root1 = root1 -> next;
//     }
//     printf("----------------------------------\n");
// }

// nodes 1 : 1111 -> 2
// nodes 2 : 4456 -> 3
// nodes 3 : 3544 -> 4
// nodes 4 : 5847 -> NULL