# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 00:14:00 by ebennix           #+#    #+#              #
#    Updated: 2023/06/02 10:19:22 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_EXE := push_swap

B_EXE := checker

CC := cc

CFLAGS := -g -Wall -Wextra -Werror

HEADER := push_swap.h

FILES  :=  parsing/get_node			parsing/valid_args			utils/ps/above_five			utils/ps/under_five				\
		   operations/Push			operations/Reverse_rotate	operations/Rotate			operations/Swap					\
		   utils/lib/ft_atoi		utils/lib/ft_lstadd_back	utils/lib/ft_lstadd_front	utils/lib/ft_lstcreate_back		\
		   utils/lib/ft_lstlast		utils/lib/ft_lstnew			utils/lib/ft_lstsize		utils/lib/ft_lstcreate_front	\
		   utils/lib/ft_split		utils/lib/ft_strdup			utils/lib/ft_strjoin		utils/lib/ft_lstfree			\
		   utils/lib/ft_strlen		utils/lib/ft_isdigit		utils/lib/ft_strchr			utils/ps/position_checker		\
		   utils/ps/error			utils/ps/init				utils/ps/get_index     										\

M_FILES := Mandatory/mandatory_main		Mandatory/push_swap																	\

B_FILES := Bonus/bonus_main			utils/lib/ft_strncmp		utils/gnl/get_next_line		Bonus/checker 					\

M_SRC := $(M_FILES:=.c) $(FILES:=.c)
M_OBJ := $(M_SRC:.c=.o)
B_SRC := $(B_FILES:=.c) $(FILES:=.c)
B_OBJ := $(B_SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush


all : $(M_EXE)

bonus : $(B_EXE)

$(M_EXE) : $(M_OBJ)
	$(CC) $(M_OBJ) -o $(M_EXE)

$(B_EXE) : $(B_OBJ)
	$(CC) $(B_OBJ) -o $(B_EXE)

%.o : %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(M_OBJ) $(B_OBJ)

fclean : clean
	$(RM) $(M_EXE) $(B_EXE)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all bonus clean fclean re git
