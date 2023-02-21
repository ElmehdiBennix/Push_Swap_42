/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 04:50:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/21 21:10:57 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft.h"

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while(lst)
    {
        lst = lst -> next;
        i++;
    }
    return (i);
}

// int main ()
// {
//     t_list *head = ft_lstnew("m - ");
//     t_list *node1 = ft_lstnew("e - ");
//     head -> next = node1;
//     t_list *node2 = ft_lstnew("h - ");
//     node1 ->next = node2;
//     t_list *node3 = ft_lstnew("d - ");
//     node2 -> next = node3;
//     t_list *newfirst = ft_lstnew("i - ");
//     ft_lstadd_front(&head,newfirst);
//     t_list *p = head;
//     int i =ft_lstsize(head);
//     while(p)
//     {
//         printf("%s",p -> content);
//         p = p -> next;
//     }
//     printf("%d",i);
// }