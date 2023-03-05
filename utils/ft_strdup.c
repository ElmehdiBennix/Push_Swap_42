/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:10:41 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 09:22:13 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dub;

	i = 0;
	dub = (char *)malloc((ft_strlen(s)+ 1) * sizeof(char));
	if (!dub)
		return (NULL);
	while (s[i] != '\0')
	{
		dub[i] = s[i];
		i++;
	}
	dub[i] = '\0';
	return (dub);
}
