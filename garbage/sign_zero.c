/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:58:50 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/22 04:32:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

char *sign_zero(char *p) //remove zeros and add signs
{
	char *sign = NULL;

	if (*p && *p == ' ')
		while (*p && *p == ' ')
			p++;
	if (*p == '-')
	{
		sign = "-";
		p++;
		while (*p)
		{
			if (*p == '0')
			{
				p++;
				if (*p == '\0')
					return (ft_strdup(--p));
			}
			else
				break;
		}
	}
	else if (*p == '+' || ft_isdigit(*p))
	{
		sign = "+";
		if (*p == '+')
			p++;
		while (*p)
		{
			if (*p == '0')
			{
				p++;
				if (*p == '\0')
					return (ft_strdup(--p));
			}
			else
				break;
		}
	}
	return (ft_strjoin(sign,p));
}
