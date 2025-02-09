/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:06:01 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/02 09:35:29 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	int	fewer_moves(int stack_size, int last, int before_last_index)
{
	int	mv_last;
	int	mv_bef;
	int	half;

	mv_last = 0;
	mv_bef = 0;
	half = stack_size / 2;
	if (last <= half)
		mv_last = last;
	else if (last > half)
		mv_last = stack_size - last +1;
	if (before_last_index <= half)
		mv_bef = before_last_index;
	else if (before_last_index > half)
		mv_bef = stack_size - before_last_index +1;
	if (mv_last <= mv_bef)
		return (0);
	else
		return (1);
}

static	void	smart_rotate(t_list **stack_a, t_list **stack_b,
			int before_last_index, int *lstlen)
{
	if (before_last_index <= ((*lstlen) / 2))
		while (before_last_index != (*stack_b)->index)
			rotate(stack_a, stack_b, 'b', TRUE);
	else
		while (before_last_index != (*stack_b)->index)
			reverse_rotate(stack_a, stack_b, 'b', TRUE);
	push(stack_a, stack_b, 'a', TRUE);
	(*lstlen)--;
}

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

static	void	push_to_a(t_list **stack_a, t_list **stack_b, int lstlen)
{
	bool	status;
	bool	less_moves;
	int		last;
	int		before_last_index;

	while (*stack_b)
	{
		status = FALSE;
		init_index(*stack_b);
		last = get_index(*stack_b, lstlen - 1);
		before_last_index = get_index(*stack_b, lstlen - 2);
		less_moves = fewer_moves(lstlen - 1, last, before_last_index);
		if (less_moves == 1)
		{
			smart_rotate(stack_a, stack_b, before_last_index, &lstlen);
			init_index(*stack_b);
			status = TRUE;
		}
		if (status == TRUE)
			last = get_index(*stack_b, lstlen);
		smart_rotate(stack_a, stack_b, last, &lstlen);
		if (status == TRUE)
			swap(stack_a, stack_b, 'a', TRUE);
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
