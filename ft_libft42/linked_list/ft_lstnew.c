/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:37:18 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/21 20:49:52 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *node;
    node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL)
        return(NULL);
    node -> content = content ;
    node -> next = NULL ;
    return (node);
}

// int main ()
// {
//     t_list *head = ft_lstnew("mehdi");
//     t_list *node1 = ft_lstnew(" hamza");
//     head -> next = node1;
//     t_list *node2 =ft_lstnew(" ahmad");
//     node1 -> next = node2;
//     while(head)
//     {
//         printf("%s",head -> content);
//         head = head -> next;
//     }
// }