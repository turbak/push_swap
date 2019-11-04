NAME2 = push_swap
NAME1 = checker
FILES2 =	push_swap.c\
			array_funcs.c\
			stack.c\
			write_stacks.c\
			sort_funcs.c\
			sort_misc_funcs.c\
			freeall.c
			
FILES1 = 	checker.c\
			array_funcs.c\
			stack.c\
			write_stacks.c

OBJ1 = $(patsubst %.c, %.o, $(FILES1))
OBJ2 = $(patsubst %.c, %.o, $(FILES2))
FLAGS		=  -Wall -Werror -Wextra
HEADER		= push_swap.h

all: push_swap checker

push_swap: $(NAME2)

checker: $(NAME1)

.PHONY: clean fclean re

$(NAME1): $(OBJ1)
	$(MAKE) -C libft all
	gcc -o $(NAME1) $(OBJ1) ./libft/libft.a

$(NAME2): $(OBJ2)
	$(MAKE) -C libft all
	gcc -o $(NAME2) $(OBJ2) ./libft/libft.a

%.o: %.c $(HEADER)
	gcc -I . $(FLAGS) $< -c -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) && $(MAKE) clean -C ./libft

fclean:clean
	rm -f $(NAME1) $(OBJ2) && $(MAKE) fclean -C ./libft

re: fclean all
