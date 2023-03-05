/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:42:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/05 12:09:09 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_memcmp(void *s1,void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (p1[i] == p2[i] && i < n - 1)
		i++;
	return (p1[i] - p2[i]);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	while(*(++av))
// 	{
// 		printf("%s\n",*av);
// 	}
// 	// int *d = (int *)15221;
// 	// int *f = (int *)15222;
// 	// printf("%d",ft_memcmp(&d,&f,1));
// }