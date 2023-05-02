/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:06:01 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/02 21:48:54 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	void	push_to_b(t_list **stack_a, t_list **stack_b,
							int chunk, int reset)
{
	int	mid;

	mid = chunk / 2;
	while (*stack_a && chunk > 0)
	{
		if ((*stack_a)->position <= reset)
		{
			if ((*stack_a)->position <= reset - mid)
				push(stack_a, stack_b, 'b', TRUE);
			else
			{
				push(stack_a, stack_b, 'b', TRUE); // if size_b > 2 rotate
				rotate(stack_a, stack_b, 'b', TRUE);
			}
			chunk--;
		}
		else 
			rotate(stack_a, stack_b, 'a', TRUE);
	}
}

static	void	push_to_a(t_list **stack_a, t_list **stack_b, int lstlen)
{
	int	index;
	int	index2;

	while (*stack_b)
	{
		init_index(*stack_b);
		index = get_index(*stack_b, lstlen);
		index2 = get_index(*stack_b, lstlen - 1);
		if ((*stack_b)->position == lstlen)
		{
			push(stack_a, stack_b, 'a', TRUE);
			lstlen--;
		}
		else if (index <= lstlen / 2)
			rotate(stack_a, stack_b, 'b', TRUE);
		else if (index >= lstlen / 2)
			reverse_rotate(stack_a, stack_b, 'b', TRUE);
	}
}
// double check
void	sort_chunks(int size, t_list **stack_a, t_list **stack_b, int divide)
{
	int	chunk;
	int	reset;
	int	lstlen;

	chunk = size / divide;
	reset = chunk;
	while (ft_lstsize(*stack_a))
	{
		push_to_b(stack_a, stack_b, chunk, reset);
		reset += chunk;
	}
	lstlen = ft_lstsize(*stack_b) - 1;
	push_to_a(stack_a, stack_b, lstlen);
}
