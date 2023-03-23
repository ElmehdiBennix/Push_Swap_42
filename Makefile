# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 00:14:00 by ebennix           #+#    #+#              #
#    Updated: 2023/03/23 02:50:10 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_EXE := push_swap

B_EXE := checker

CC := cc

CFLAGS := -g -Wall -Wextra -Werror

HEADER := push_swap.h

FILES  := Mandatory/push_swap		parsing/get_node			parsing/valid_args										  \
		  operations/Push			operations/Reverse_rotate	operations/Rotate			operations/Swap				  \
		  utils/lib/ft_atoi			utils/lib/ft_lstadd_back	utils/lib/ft_lstadd_front	utils/lib/ft_lstcreate_back	  \
		  utils/lib/ft_lstlast		utils/lib/ft_lstnew			utils/lib/ft_lstsize		utils/lib/ft_lstcreate_front  \
		  utils/lib/ft_split		utils/lib/ft_strdup			utils/lib/ft_strjoin		utils/lib/ft_lstfree		  \
		  utils/lib/ft_strlen		utils/lib/ft_isdigit			 													  \
		  utils/ps/error			utils/ps/init				utils/ps/get_index     		utils/ps/under_five			  \
		  utils/ps/above_five		 																					  \

M_FILES := Mandatory/mandatory_main																						  \

B_FILES := Bonus/bonus_main		Bonus/checker		utils/gnl/get_next_line		utils/lib/ft_strchr						  \

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
