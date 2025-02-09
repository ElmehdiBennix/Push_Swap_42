/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:40:20 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/02 10:07:58 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	bool	sort_status(t_list	**stack_a)
{
	int		i;
	bool	err;
	t_list	*arrow;

	i = 0;
	err = FALSE;
	arrow = *stack_a;
	while (arrow -> next)
	{
		if (arrow -> position != i)
			err = TRUE;
		i++;
		arrow = arrow -> next;
	}
	return (err);
}

int	position_checker(t_list	**stack_a, t_list	**stack_b, bool flag)
{
	bool	err ;

	err = sort_status(stack_a);
	if (err == TRUE || (*stack_b) != NULL)
	{
		if (flag == TRUE)
			write(1, "KO\n", 3);
		return (1);
	}
	else if (err == FALSE && (*stack_b) == NULL)
	{
		if (flag == TRUE)
			write(1, "OK\n", 3);
	}
	return (0);
}
