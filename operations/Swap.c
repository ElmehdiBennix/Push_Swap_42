/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:27:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/26 01:51:38 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	stack_swap(t_list **stack)
{
	t_list	*arrow;
	int		i;

	arrow = *stack;
	if (!arrow || !arrow->next)
		return (1);
	i = arrow->content;
	arrow->content = arrow->next->content;
	arrow->next->content = i;
	i = arrow->position;
	arrow->position = arrow->next->position;
	arrow->next->position = i;
	return (0);
}

void	swap(t_list **stack_a, t_list **stack_b, char operation, int print)
{
	unsigned int	err[2];

	if (operation == 'a')
	{
		if (stack_swap(stack_a) == 0 && print == TRUE)
			write(1, "sa\n", 4);
	}
	else if (operation == 'b')
	{
		if (stack_swap(stack_b) == 0 && print == TRUE)
			write(1, "sb\n", 4);
	}
	else if (operation == 's')
	{
		err[0] = stack_swap(stack_a);
		err[1] = stack_swap(stack_b);
		if ((err[0] == 0 || err[1] == 0) && print == TRUE)
			write(1, "ss\n", 4);
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
//     swap(&root1,&root2,'a');
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