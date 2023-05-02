/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:11:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/02 02:47:31 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	exec_operation(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		push(stack_a, stack_b, 'a', FALSE);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		push(stack_a, stack_b, 'b', FALSE);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		swap(stack_a, stack_b, 'a', FALSE);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		swap(stack_a, stack_b, 'b', FALSE);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		swap(stack_a, stack_b, 's', FALSE);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		rotate(stack_a, stack_b, 'a', FALSE);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rotate(stack_a, stack_b, 'b', FALSE);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rotate(stack_a, stack_b, 'r', FALSE);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		reverse_rotate(stack_a, stack_b, 'a', FALSE);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		reverse_rotate(stack_a, stack_b, 'b', FALSE);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
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

int	position_checker(t_list	**stack_a, t_list	**stack_b, int flag)
{
	int	i ;
	int	err ;

	i = 0;
	err = FALSE;
	t_list *arrow = *stack_a;
	while (arrow -> next)
	{
		if (arrow -> position != i)
			err = TRUE;
		i++;
		arrow = arrow -> next;
	}
	if (err == FALSE && (*stack_b) == NULL)
	{
		if(flag == TRUE)
			write(1, "OK\n", 3);
		return (0);
	}
	if (err == TRUE || (*stack_b) != NULL)
	{
		if(flag == TRUE)
			write(1, "KO\n", 3);
		return(1);
	}
	return (0);
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
	position_checker(&stack_a, &stack_b,1);
	ft_lstfree(stack_a);
	return (0);
}
