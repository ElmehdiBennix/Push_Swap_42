
EXE := push_swap

LIB := ft_libft42/libft.a

CC := cc

CFLAGS := -g -Wall -Wextra

HEADER := push_swap.h

FILES := push_swap utils/ft_atoi \

SRC := $(FILES:=.c)
OBJ := $(SRC:.c=.o)

RM := rm -rf

m := MakefileAutoPush

all : $(EXE)

$(EXE) : $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) -o $(EXE)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	cd ft_libft42 && $(MAKE)

clean :
	$(RM) $(OBJ)
	cd ft_libft42 && $(RM) *.o

fclean : clean
	$(RM) $(EXE)
	cd ft_libft42 && $(RM) *.a

re : fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY : all clean fclean re git


