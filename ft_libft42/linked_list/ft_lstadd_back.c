/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:06:46 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/22 05:13:59 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *p;

    p = *lst;
    while(p -> next != NULL)
        p = p -> next;
    p -> next = new;
}
