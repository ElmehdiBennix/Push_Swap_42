/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:13:37 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 11:58:30 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int push_swap(int ac, char **av)
{
    t_list *res ;

    check_valid (av); // if it passed means arguments are valid
    res = split_args(ac, av); //joinning for the split

    // t_list *root = ft_lstnew(ft_atoi(*res));
    // t_list *arrow = root;
    // while(*(++res))
    //     ft_lstcreate_back(&root,ft_atoi(*res));
    // while (arrow)
    // {
    //     printf("%d\n",arrow -> content);
    //     free(arrow);
    //     arrow = arrow -> next;
    // }
    return (0);
}

int main (int ac, char **av)
{
    int err;
    
    if (ac == 1)
        failure(1);
    err = push_swap(ac,av);
    
    // while(1)
    //     sleep(1);
    
    return (err);
}
