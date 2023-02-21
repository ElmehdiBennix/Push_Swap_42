/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:06:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/21 22:17:47 by ebennix          ###   ########.fr       */
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

int main ()
{
    t_list *head = ft_lstnew("1 - ");
    t_list *node1 = ft_lstnew("2 - ");
    head -> next = node1;
    t_list *node2 = ft_lstnew("3 - ");
    node1 ->next = node2;
    t_list *node3 = ft_lstnew("4 - ");
    node2 -> next = node3;
    
    t_list *show = ft_lstlast(head);
    printf("%s",show -> content);
}