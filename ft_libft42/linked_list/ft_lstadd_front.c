/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:21:57 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/21 21:07:32 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// lst is head and we want to make new the head
void ft_lstadd_front(t_list **lst, t_list *new)
{
    new -> next = *lst;
    *lst = new;
}
// int main ()
// {
//     t_list *head = ft_lstnew("mhedi");
//     t_list *node1 = ft_lstnew("mhedi");
//     head -> next = node1;
//     t_list *node2 = ft_lstnew("mhedi");
//     node1 ->next = node2;
//     t_list *node3 = ft_lstnew("mhedi");
//     t_list *newfirst = ft_lstnew("first");
//     ft_lstadd_front(&head,newfirst);
//     t_list *p = head;
//     while(p)
//     {
//         printf("%s",p -> content);
//         p = p -> next;
//     }
// }