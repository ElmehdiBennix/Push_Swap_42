/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:11:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/25 02:54:33 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// #define SORTED = 0;
// #define NOT_SORTED = 1;

void check_line(char **line, t_list **stack_a, t_list **stack_b)
{
	*line = get_next_line(0);

	if (ft_strncmp(*line,"pa\n",3) == 0)
		push(stack_a, stack_b, 'a');
	else if (ft_strncmp(*line,"pb\n",3) == 0)
		push(stack_a, stack_b, 'b');
	else if (ft_strncmp(*line,"sa\n",3) == 0)
		swap(stack_a, stack_b, 'a');
	else if (ft_strncmp(*line,"sb\n",3) == 0)
		swap(stack_a, stack_b, 'b');
	else if (ft_strncmp(*line,"ss\n",3) == 0)
		swap(stack_a, stack_b, 's');
	else if (ft_strncmp(*line,"ra\n",3) == 0)
		rotate(stack_a, stack_b, 'a');
	else if (ft_strncmp(*line,"rb\n",3) == 0)
		rotate(stack_a, stack_b, 'b');
	else if (ft_strncmp(*line,"rr\n",3) == 0)
		rotate(stack_a, stack_b, 'r');
	else if (ft_strncmp(*line,"rra\n",4) == 0)
		reverse_rotate(stack_a, stack_b, 'a');
	else if (ft_strncmp(*line,"rrb\n",4) == 0)
		reverse_rotate(stack_a, stack_b, 'b');
	else if (ft_strncmp(*line,"rrr\n",4) == 0)
		reverse_rotate(stack_a, stack_b, 'r');
	else
		failure(1);
}

void	position_checker(t_list	**stack_a, t_list	**stack_b)
{
	t_list *arrow = *stack_a;

	int i = 0;
	int err;

	while (arrow -> next)
	{
		if(arrow ->position != i)
			err = 1;
		arrow = arrow -> next;
	}
	if (err == 0 && (*stack_b) == NULL)
		write(2,"OK\n",3);
	if (err == 1 || (*stack_b) != NULL)
		write(2,"KO\n",3);
}

int	checker(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	// int		size;

	check_valid(av);
	stack_a = get_node(ac, av);
	stack_b = NULL;
	init_position(stack_a);
	char *line;
	while (1)
	{ // first eteration dosent show up and segfult
		check_line(&line ,&stack_a ,&stack_b); // expand on this with a checker and executer for stacks
		if (line == 0)
			break;
	}
	position_checker(&stack_a,&stack_b);
	ft_lstfree(stack_a);
	return (0);
}

	// if stack a is sorted and stack_b is null then it writes OK\n in stdout
	// else it displays KO\n
	/*

	 	$> ./checker 3 2 1 0
				rra
				pb
				sa
				rra
				pa
				OK
			$> ./checker 3 2 1 0
				sa
				rra
				pb
				KO
	*/
