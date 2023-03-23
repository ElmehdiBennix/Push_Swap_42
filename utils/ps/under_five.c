/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bennix <bennix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:24:47 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/21 23:21:58 by bennix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	under_five_to_b(t_list **stack_a, t_list **stack_b, int position)
{
	t_list	*arrow;

	arrow = *stack_a;
	while (arrow->position != position)
		arrow = arrow->next;
	if (arrow->index == 0 || arrow->index == 1)
	{
		while ((*stack_a)->position != position)
			rotate(stack_a, stack_b, 'a');
		push(stack_a, stack_b, 'b');
	}
	else
	{
		while ((*stack_a)->position != position)
			reverse_rotate(stack_a, stack_b, 'a');
		push(stack_a, stack_b, 'b');
	}
}

static void	size_tree(t_list **stack_a, t_list **stack_b)
{
	t_list	*arrow;

	arrow = *stack_a;
	if (arrow->position == 1 && arrow->next->position == 0)
		swap(stack_a, stack_b, 'a');
	else if (arrow->position == 2 && arrow->next->position == 1)
	{
		swap(stack_a, stack_b, 'a');
		reverse_rotate(stack_a, stack_b, 'a');
	}
	else if (arrow->position == 2 && arrow->next->position == 0)
		rotate(stack_a, stack_b, 'a');
	else if (arrow->position == 0 && arrow->next->position == 2)
	{
		swap(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
	else if (arrow->position == 1 && arrow->next->position == 2)
		reverse_rotate(stack_a, stack_b, 'a');
}

static void	size_four(t_list **stack_a, t_list **stack_b)
{
	under_five_to_b(stack_a, stack_b, 0);
	init_position(*stack_a);
	size_tree(stack_a, stack_b);
	push(stack_a, stack_b, 'a');
}

static void	size_five(t_list **stack_a, t_list **stack_b)
{
	under_five_to_b(stack_a, stack_b, 0);
	init_index(*stack_a);
	under_five_to_b(stack_a, stack_b, 1);
	init_position(*stack_a);
	size_tree(stack_a, stack_b);
	push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
}

void	sort_under_five(int size, t_list **stack_a, t_list **stack_b)
{
	if (size == 2 && (*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, stack_b, 'a');
	else if (size == 3)
		size_tree(stack_a, stack_b);
	else if (size == 4)
		size_four(stack_a, stack_b);
	else if (size == 5)
		size_five(stack_a, stack_b);
	init_position(*stack_a);
	init_index(*stack_a);
}
