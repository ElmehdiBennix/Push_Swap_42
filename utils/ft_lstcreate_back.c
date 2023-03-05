/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 05:09:22 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 15:39:13 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstcreate_back(t_list **lst, int content)
{
	t_list	*back;

	back = ft_lstnew(content);
	ft_lstadd_back(lst, back);
}
