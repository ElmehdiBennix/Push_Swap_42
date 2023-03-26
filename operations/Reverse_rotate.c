/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:26:41 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/26 01:52:05 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	reverse_rotate_stack(t_list **stack)
{
	t_list	*arrow;
	t_list	*second_last;

	arrow = *stack;
	second_last = NULL;
	if (!arrow || !arrow->next)
		return (1);
	while (arrow->next)
	{
		second_last = arrow;
		arrow = arrow->next;
	}
	second_last->next = NULL;
	ft_lstadd_front(stack, arrow);
	return (0);
}

void	reverse_rotate(t_list **stack_a, t_list **stack_b, char operation, int print)
{
	unsigned int	err[2];

	if (operation == 'a')
	{
		if (reverse_rotate_stack(stack_a) == 0 && print == TRUE)
			write(1, "rra\n", 5);
	}
	else if (operation == 'b')
	{
		if (reverse_rotate_stack(stack_b) == 0 && print == TRUE)
			write(1, "rrb\n", 5);
	}
	else if (operation == 'r')
	{
		err[0] = reverse_rotate_stack(stack_a);
		err[1] = reverse_rotate_stack(stack_b);
		if ((err[0] == 0 || err[1] == 0) && print == TRUE)
			write(1, "rrr\n", 5);
	}
}

// int main ()
// {
//     t_list *root1 = ft_lstnew(90000);
//     // ft_lstcreate_back(&root1,768);
//     // ft_lstcreate_back(&root1,1);
//     // ft_lstcreate_back(&root1,50);
//     t_list *root2 = ft_lstnew(50000);
//     ft_lstcreate_back(&root2,5479);
//     // ft_lstcreate_back(&root2,1575);
//     // ft_lstcreate_back(&root2,54356);
//     reverse_rotate(&root1,&root2,'r');
//     while(root1)
//     {
//         printf("stack a :");
//         printf("%d\n",root1->content);
//         // printf("%d and p = %p \n",root1->content,root1->next);
//         // printf("%d and p = %p \n",root1->content,root1->next);
//         root1 = root1 -> next;
//     }
//     printf("----------------------------------\n");
//     while(root2)
//     {
//         printf("stack b :");
//         printf("%d\n",root2->content);
//         // printf("%d and p = %p \n",root2->content,root2->next);
//         // printf("%d and p = %p \n",root2->content,root2->next);
//         root2 = root2 -> next;
//     }
//     printf("----------------------------------\n");
// }
