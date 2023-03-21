
EXE := push_swap

LIB := ft_libft42/libft.a

CC := cc

CFLAGS := -g -Wall -Wextra 
# -Werror

HEADER := push_swap.h

FILES := push_swap		parsing/split_args		parsing/valid_args \
		 operations/Push	operations/Reverse_rotate		operations/Rotate	operations/Swap \
		 utils/lib_utils/ft_atoi 	utils/lib_utils/ft_lstadd_back  utils/lib_utils/ft_lstadd_front  utils/lib_utils/ft_lstcreate_back	\
		 utils/lib_utils/ft_lstcreate_front	\
		 utils/lib_utils/ft_lstlast	utils/lib_utils/ft_lstnew		utils/lib_utils/ft_lstsize	utils/lib_utils/ft_split	utils/lib_utils/ft_strdup \
		 utils/lib_utils/ft_strjoin \
		 utils/lib_utils/ft_strlen  utils/lib_utils/ft_isdigit	utils/ps_utils/error		utils/ps_utils/init		utils/ps_utils/get_index	\
		 utils/ps_utils/under_five	\

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

.PHONY : all clean fclean re git


