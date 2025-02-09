/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:06:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/21 21:36:48 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*arrow;

	arrow = lst;
	if (arrow)
		while (arrow -> next != NULL)
			arrow = arrow -> next;
	return (arrow);
}
