/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:06:01 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/07 04:15:20 by ebennix          ###   ########.fr       */
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
				push(stack_a, stack_b, 'b', TRUE);
				rotate(stack_a, stack_b, 'b', TRUE);
			}
			chunk--;
		}
		else 
			rotate(stack_a, stack_b, 'a', TRUE);
	}
}

// {return == 1 : {last <= before_last} ; return == 2 : before_last < last}
int	which_has_fewer_moves(int stack_size, int last, int before_last_index)
{
	int	mv_last = 0;
	int	mv_bef = 0;
	int	half = stack_size / 2;

	// printf("===> last=%d | before=%d | len = %d \n", last, before_last_index, stack_size);
	if (last <= half)
		mv_last = last;
	else if (last > half)
		mv_last = stack_size - last +1;

	if (before_last_index <= half)
		mv_bef = before_last_index;
	else if (before_last_index > half)
		mv_bef = stack_size - before_last_index +1;

	if (mv_last <= mv_bef)
		return (1);
	else if (mv_bef < mv_last)
		return (2);
	return (0);
}

static	void	push_to_a(t_list **stack_a, t_list **stack_b, int lstlen)
{
	int	last = 0;
	int	before_last_index = 0; 
	int	less_moves = 0;
	int	bool = 0;
	while (lstlen > 0)
	{
		bool = 0;
		init_index(*stack_b);
		last = get_index(*stack_b, lstlen - 1); // 99
		before_last_index = get_index(*stack_b, lstlen - 2); // 98
		less_moves = which_has_fewer_moves(lstlen - 1, last, before_last_index);
		// printf("last=%d | before=%d | len = %d | lessmoves=%d \n", last, before_last_index, lstlen, less_moves);
        if (less_moves == 2)
		{
			// printf("[les_mv=2]\n");
			if (before_last_index <= (lstlen / 2))
				while (before_last_index != (*stack_b)->index)
					rotate(stack_a, stack_b, 'b', TRUE); // rb
			else
				while (before_last_index != (*stack_b)->index)
					reverse_rotate(stack_a, stack_b, 'b', TRUE); // rrb
			// printf("pos= %d | idx = %d\n", (*stack_b)->position, (*stack_b)->index);
			push(stack_a, stack_b, 'a', TRUE); // pa
			init_index(*stack_b);
			lstlen -= 1;
			bool = 1;
		}
		// {	
		if (bool == 1)
			last = get_index(*stack_b, lstlen); // 99
		// 	before_last_index = get_index(*stack_b, lstlen - 2); // 98
		// }
		// printf("[les_mv=1]\n");
		if (last <= (lstlen / 2))
			while (last != (*stack_b)->index)
				rotate(stack_a, stack_b, 'b', TRUE); // rb
		else
			while (last != (*stack_b)->index)
				reverse_rotate(stack_a, stack_b, 'b', TRUE); // rrb
		// printf("pos= %d | idx = %d\n", (*stack_b)->position, (*stack_b)->index);
		push(stack_a, stack_b, 'a', TRUE); // pa
		lstlen--;
		if (bool == 1)
			swap(stack_a, stack_b, 'a', TRUE); // sa
	}
}

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
	lstlen = ft_lstsize(*stack_b);
	push_to_a(stack_a, stack_b, lstlen);
}
