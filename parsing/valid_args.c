/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:59:52 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/21 21:13:08 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_valid(char **av)
{
	char *tmp;
	unsigned int allowed;

	while (*(++av))
	{
		tmp = *av;
		allowed = 0;
		if (*tmp == '\0')
			failure(1);
		while (*tmp != '\0')
		{
			if (*tmp == ' ')
				tmp++;
			else if (ft_isdigit(*tmp) || *tmp == '+' || *tmp == '-')
			{
				allowed++;
				tmp++;
			}
			else if (*tmp == '*')
				failure(2);
			else 
				failure(2);
		}
		if (allowed == 0)
			failure(3);
		tmp = *av;
		while (*tmp != '\0')
		{
			allowed = 0;
			while (*tmp == ' ')
				tmp++;
			while (ft_isdigit(*tmp))
			{
				allowed++;
				tmp++;
			}
			if (*tmp == '+' || *tmp == '-')
			{
				tmp++;
				if (ft_isdigit(*tmp))
				{
					if (allowed > 0)
						failure(4);
					tmp++;
				}
				else if (*tmp == '\0')
					failure(5);
				else if (*tmp == ' ')
					failure(6);
				else if (*tmp == '+' || *tmp == '-')
					failure(7);
			}
		}
	}
}