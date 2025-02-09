/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:26:38 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/02 03:43:34 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_list **stack_a, t_list **stack_b, char operation, int print)
{
	t_list	*tmp;

	if (operation == 'a')
	{
		if (!(*stack_b))
			return ;
		tmp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = tmp;
		if (print == TRUE)
			write(1, "pa\n", 3);
	}
	else if (operation == 'b')
	{
		if (!(*stack_a))
			return ;
		tmp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = tmp;
		if (print == TRUE)
			write(1, "pb\n", 3);
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
//     push(&root1,&root2,'h');
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
