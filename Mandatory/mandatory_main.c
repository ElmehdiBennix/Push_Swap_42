/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:24:35 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/23 02:58:44 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	int	err;

	if (ac == 1)
		exit(1);
	err = push_swap(ac, av);
	// system("leaks push_swap");
	return (err);
}

// optimization and bonus and rename + making every thing look pretty ;3
