/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:06:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/22 05:14:09 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list *arrow;
    
    arrow = lst;
    while (arrow ->next != NULL)
        arrow = arrow -> next;
    return (arrow);
}
