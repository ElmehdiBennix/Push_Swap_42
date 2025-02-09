/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:18:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/07 03:17:00 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	init_index(t_list *stack)
{
	t_list	*arrow;
	int		i;

	arrow = stack;
	i = 0;
	while (arrow)
	{
		arrow->index = i++;
		arrow = arrow->next;
	}
}

void	init_position(t_list *stack)
{
	t_list	*arrow;
	t_list	*p;

	arrow = stack;
	while (arrow)
	{
		arrow->position = 0;
		arrow = arrow->next;
	}
	arrow = stack;
	while (arrow)
	{
		p = stack;
		while (p)
		{
			if (arrow->content < p->content)
				p->position += 1;
			p = p->next;
		}
		arrow = arrow->next;
	}
}
