/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:29:24 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/23 02:29:38 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	int	err;
    // char *line;

	if (ac == 1)
		exit(1);
    err = push_swap(ac, av);
    // while (1)
    // {
    //     line = get_next_line(1);
    //     if(!line)
    //         break;
    // }
	// err = checker(ac, av ,line);
	system("leaks push_swap");
	return (err);
}