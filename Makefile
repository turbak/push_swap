NAME2 = push_swap
NAME1 = checker
LIBFT = ./libft/libft.a
FILES2 =	push_swap.c\
			sort_funcs.c\
			sort_misc_funcs.c\
			hardcoded_algo.c

FILES1 = 	checker.c\

FILES3 = 	array_funcs.c\
			stack.c\
			other_stack_funcs.c\
			read_funcs.c\
			freeall.c\
			shared_funcs.c\
			write_stacks.c\
			write_bonus.c

OBJ1 = $(patsubst %.c, %.o, $(FILES1))
OBJ2 = $(patsubst %.c, %.o, $(FILES2))
OBJ3 = $(patsubst %.c, %.o, $(FILES3))
CPPFLAGS		=  -Wall -Werror -Wextra
HEADER		= push_swap.h
NAME 		= $(NAME1) $(NAME2)

all: $(NAME)

$(LIBFT):
	$(MAKE) -sC libft all

$(NAME1): $(OBJ1) $(OBJ3)
	gcc $(CPPFLAGS) -o $(NAME1) $(OBJ1) $(OBJ3) $(LIBFT)

$(NAME2): $(OBJ2) $(OBJ3)
	gcc $(CPPFLAGS) -o $(NAME2) $(OBJ2) $(OBJ3) $(LIBFT)

%.o: %.c $(HEADER) $(LIBFT)
	gcc -I . $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) && $(MAKE) clean -C ./libft

fclean:clean
	rm -f $(NAME1) $(NAME2) && $(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean fclean re all