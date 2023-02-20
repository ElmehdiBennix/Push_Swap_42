# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 21:51:22 by ebennix           #+#    #+#              #
#    Updated: 2023/02/20 22:03:16 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := push_swap

CC := cc

CFLAGS := -g -Wall -Wextra -Werror

HEADER := push_swap.h

FILES := 

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

force :
	git push --force

.PHONY : all clean fclean re git

