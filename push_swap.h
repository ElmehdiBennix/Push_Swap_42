/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:05:38 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/09 18:10:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_list
{
    int            content;
    struct s_list   *next;
}   t_list;

//parsing and error
void failure(int err);
t_list *split_args(int ac , char **av);
void check_valid(char **av); // check for valid arguments

//operation funcs
void swap(t_list **stack);
void ss(t_list **stack_a, t_list **stack_b);
void push(t_list **stack_a, t_list **stack_b , char stack);
void reverse_rotate(t_list **stack);
void rrr(t_list **stack_a, t_list **stack_b);
void rotate(t_list **stack);
void rr(t_list **stack_a, t_list **stack_b);

//libft funcs
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int     ft_atoi(char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char delim);
char	**free_2d(char **str);

// linked list funcs
int		ft_lstsize(t_list *lst);
void	ft_lstcreate_front(t_list **lst, int content);
void	ft_lstcreate_back(t_list **lst, int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);

#endif
