/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:11:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/02 09:43:14 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void	exec_operation(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push(stack_a, stack_b, 'a', FALSE);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(stack_a, stack_b, 'b', FALSE);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(stack_a, stack_b, 'a', FALSE);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(stack_a, stack_b, 'b', FALSE);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap(stack_a, stack_b, 's', FALSE);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(stack_a, stack_b, 'a', FALSE);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(stack_a, stack_b, 'b', FALSE);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate(stack_a, stack_b, 'r', FALSE);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate(stack_a, stack_b, 'a', FALSE);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate(stack_a, stack_b, 'b', FALSE);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		reverse_rotate(stack_a, stack_b, 'r', FALSE);
	else
		failure(1);
}

static	void	check_line(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_operation(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
}

int	checker(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	check_valid(av);
	stack_a = get_node(ac, av);
	stack_b = NULL;
	init_position(stack_a);
	check_line(&stack_a, &stack_b);
	position_checker(&stack_a, &stack_b, 1);
	ft_lstfree(stack_a);
	return (0);
}
