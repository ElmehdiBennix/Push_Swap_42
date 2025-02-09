/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:59:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/26 05:43:24 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	char	**split_args(int ac, char **av)
{
	int		i;
	char	*str;
	char	**res;

	i = 1;
	while (*(++av) && ac > i)
	{
		if (i == 1)
			str = ft_strdup(*av);
		else
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, *av);
		}
		i++;
	}
	res = ft_split(str, ' ');
	if (!res)
		free(res);
	free(str);
	return (res);
}

static	void	check_dup(t_list	**root)
{
	t_list	*arrow;
	t_list	*p;

	arrow = *root;
	while (arrow)
	{
		p = arrow->next;
		while (p)
		{
			if (arrow->content == p->content)
			{
				ft_lstfree(*root);
				failure(2);
			}
			p = p->next;
		}
		arrow = arrow->next;
	}
}

t_list	*get_node(int ac, char **av)
{
	char	**res;
	char	**tmp;
	t_list	*root;

	res = split_args(ac, av);
	tmp = res;
	root = ft_lstnew(ft_atoi(*res));
	while (*(++res))
		ft_lstcreate_back(&root, ft_atoi(*res));
	check_dup(&root);
	free_2d(tmp);
	return (root);
}
