/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:24:47 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/07 03:16:34 by ebennix          ###   ########.fr       */
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
			rotate(stack_a, stack_b, 'a', TRUE);
		push(stack_a, stack_b, 'b', TRUE);
	}
	else
	{
		while ((*stack_a)->position != position)
			reverse_rotate(stack_a, stack_b, 'a', TRUE);
		push(stack_a, stack_b, 'b', TRUE);
	}
}

static void	size_tree(t_list **stack_a, t_list **stack_b)
{
	t_list	*arrow;

	arrow = *stack_a;
	if (arrow->position == 1 && arrow->next->position == 0)
		swap(stack_a, stack_b, 'a', TRUE);
	else if (arrow->position == 2 && arrow->next->position == 1)
	{
		swap(stack_a, stack_b, 'a', TRUE);
		reverse_rotate(stack_a, stack_b, 'a', TRUE);
	}
	else if (arrow->position == 2 && arrow->next->position == 0)
		rotate(stack_a, stack_b, 'a', TRUE);
	else if (arrow->position == 0 && arrow->next->position == 2)
	{
		swap(stack_a, stack_b, 'a', TRUE);
		rotate(stack_a, stack_b, 'a', TRUE);
	}
	else if (arrow->position == 1 && arrow->next->position == 2)
		reverse_rotate(stack_a, stack_b, 'a', TRUE);
}

static void	size_four(t_list **stack_a, t_list **stack_b)
{
	under_five_to_b(stack_a, stack_b, 0);
	init_position(*stack_a);
	size_tree(stack_a, stack_b);
	push(stack_a, stack_b, 'a', TRUE);
}

static void	size_five(t_list **stack_a, t_list **stack_b)
{
	under_five_to_b(stack_a, stack_b, 0);
	init_index(*stack_a);
	under_five_to_b(stack_a, stack_b, 1);
	init_position(*stack_a);
	size_tree(stack_a, stack_b);
	push(stack_a, stack_b, 'a', TRUE);
	push(stack_a, stack_b, 'a', TRUE);
}

void	sort_under_five(int size, t_list **stack_a, t_list **stack_b)
{
	if (size == 2 && (*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, stack_b, 'a', TRUE);
	else if (size == 3)
		size_tree(stack_a, stack_b);
	else if (size == 4)
		size_four(stack_a, stack_b);
	else if (size == 5)
		size_five(stack_a, stack_b);
	init_position(*stack_a);
	init_index(*stack_a);
}
