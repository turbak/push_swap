NAME2 = push_swap
NAME1 = checker
FILES2 =	push_swap.c\
			array_funcs.c\
			stack.c\
			other_stack_funcs.c\
			sort_funcs.c\
			sort_misc_funcs.c\
			freeall.c\
			read_funcs.c\
			shared_funcs.c\
			hardcoded_algo.c
			
FILES1 = 	checker.c\
			array_funcs.c\
			stack.c\
			other_stack_funcs.c\
			read_funcs.c\
			freeall.c\
			shared_funcs.c

OBJ1 = $(FILES1:%.c=%.o)
OBJ2 = $(FILES2:%.c=%.o)
FLAGS		=  -Wall -Werror -Wextra
HEADER		= push_swap.h

all: $(NAME2) $(NAME1)

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
	rm -f $(NAME1) $(NAME2) && $(MAKE) fclean -C ./libft

re: fclean all
