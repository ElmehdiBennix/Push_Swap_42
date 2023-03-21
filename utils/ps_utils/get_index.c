/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:19:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/21 21:06:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_index(t_list *stack, int position)
{
    int index;
	t_list *arrow;

    arrow = stack;
	while (arrow->next != NULL && arrow->position != position)
		arrow = arrow->next;
	index = arrow->index;
	return (index);
}