/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/02 09:43:52 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_swap(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	check_valid(av);
	stack_a = get_node(ac, av);
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	init_index(stack_a);
	init_position(stack_a);
	if (position_checker(&stack_a, &stack_b, 0) == 0)
		return (0);
	if (size <= 5)
		sort_under_five(size, &stack_a, &stack_b);
	else if (size <= 200)
		sort_chunks(size, &stack_a, &stack_b, 5);
	else
		sort_chunks(size, &stack_a, &stack_b, 10);
	// printf("\n");
	// while(stack_a)
	// {
	// 	printf("|| stack : a = %d      with the position %d         with the index %d\n",stack_a -> content,stack_a-> position,stack_a -> index);
	// 	stack_a = stack_a -> next;
	// }
	// printf("\n");
	// while(stack_b)
	// {
	// 	printf("|| stack : b = %d      with the position %d         with the index %d\n",stack_b -> content,stack_b-> position,stack_b -> index);
	// 	stack_b = stack_b -> next;
	// }
	ft_lstfree(stack_a);
	return (0);
}
