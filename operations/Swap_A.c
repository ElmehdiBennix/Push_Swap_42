/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:27:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 17:36:21 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void sa(t_list **head)
{
    t_list *arrow;
    int i;

    arrow = *head;
    if (arrow == NULL && arrow -> next == NULL)
    {
        printf("1 or no elemets\n");
        return;
    }
    else
    {
        i = arrow -> content;
        arrow -> content = arrow -> next -> content;
        arrow -> next -> content = i;
    }
}

int main ()
{
    t_list *root = ft_lstnew(90000);
    printf("hir");
    // ft_lstcreate_back(&root,768);
    // ft_lstcreate_back(&root,1);
    // ft_lstcreate_back(&root,50);
    sa(&root);
    while(root)
    {
        printf("%d\n",root->content);
        root = root -> next;
    }

}