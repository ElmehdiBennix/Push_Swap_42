/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:59:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 15:58:47 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

t_list *split_args(int ac , char **av)
{
    int i;
    char *str;
    char **res;
    t_list *p;
    char *tmp;

    i = 1;
    while (*(++av) && ac > i)
    {
        if (i == 1)
            str = ft_strdup(*av);
        else
        {
            tmp = ft_strjoin(str , " "); // adding 2 spaces to seperate incase ;)
            free(str);
            str = ft_strjoin(tmp , *av); // tmp to free leaks hir
            free (tmp);
        }
        i++;
    }
    res = ft_split(str , ' ');
    free (str); // if incase failed double free
    t_list *root = ft_lstnew(ft_atoi(*res));
    t_list *arrow = root;
    while(*(++res))
        ft_lstcreate_back(&root,ft_atoi(*res));
    while (arrow)
    {
        p = arrow->next;
        while(p)
        {
            if(arrow->content == p->content)
                failure(2);
            p = p->next;
        }
        arrow = arrow->next;
    }
    return (root);
}