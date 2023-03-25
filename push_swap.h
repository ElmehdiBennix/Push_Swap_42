/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:05:38 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/25 02:15:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 10

typedef struct node
{
	int			content;
	int			index;
	int			position;
	struct node	*next;
}				t_list;

typedef struct operation
{
	char				*content;
	struct operation	*next;
}						s_list;

//parsing
void	check_valid(char **av);
t_list	*get_node(int ac, char **av);

//operation funcs
void	swap(t_list **stack_a, t_list **stack_b, char operation);
void	push(t_list **stack_a, t_list **stack_b, char stack);
void	reverse_rotate(t_list **stack_a, t_list **stack_b, char operation);
void	rotate(t_list **stack_a, t_list **stack_b, char operation);

//push_swap utils
void	failure(int err);
void	init_index(t_list *stack);
void	init_position(t_list *stack);
int		get_index(t_list *stack, int position);
void	sort_under_five(int size, t_list **stack_a, t_list **stack_b);
void	sort_chunks(int size, t_list **stack_a, t_list **stack_b, int divide);


int		push_swap(int ac, char **av);
int	checker(int ac, char **av);


char	*get_next_line(int fd);

//libft funcs
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char delim);
char	**free_2d(char **str);
char	*ft_strchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


// linked list funcs
int		ft_lstsize(t_list *lst);
void	ft_lstfree(void *stack);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstcreate_back(t_list **lst, int content);
void	ft_lstcreate_front(t_list **lst, int content);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);

#endif
