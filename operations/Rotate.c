/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:27:05 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/26 01:51:52 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate_stack(t_list **stack)
{
	t_list	*arrow;

	arrow = *stack;
	if (!arrow || !arrow->next)
		return (1);
	*stack = (*stack)->next;
	arrow->next = NULL;
	ft_lstadd_back(stack, arrow);
	return (0);
}

void	rotate(t_list **stack_a, t_list **stack_b, char operation, int print)
{
	unsigned int	err[2];

	if (operation == 'a')
	{
		if (rotate_stack(stack_a) == 0 && print == TRUE)
			write(1, "ra\n", 4);
	}
	else if (operation == 'b')
	{
		if (rotate_stack(stack_b) == 0 && print == TRUE)
			write(1, "rb\n", 4);
	}
	else if (operation == 'r')
	{
		err[0] = rotate_stack(stack_a);
		err[1] = rotate_stack(stack_b);
		if ((err[0] == 0 || err[1] == 0) && print == TRUE)
			write(1, "rr\n", 4);
	}
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
//     rotate(&root1,&root2,'r');
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

// nodes 1 : 1111 -> 2
// nodes 2 : 4456 -> 3
// nodes 3 : 3544 -> 4
// nodes 4 : 5847 -> NULL