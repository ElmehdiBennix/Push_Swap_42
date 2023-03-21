/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bennix <bennix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:19:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/21 19:16:32 by bennix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_index(t_list *stack, int position)
{
	t_list *arrow = stack;
	while (arrow->next != NULL && arrow->position != position)
		arrow = arrow->next;
	int index = arrow->index;
	return (index);
}