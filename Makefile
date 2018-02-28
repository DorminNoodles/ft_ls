NAME = ft_ls
CC = clang
SRC = main.c

SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix obj/, $(OBJ))
INC = -I includes -I libft/includes


all : $(NAME)

$(NAME) : obj_folder $(OBJS)
	make -C libft/
	$(CC) -g $(OBJS) $(INC) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

obj/%.o : srcs/%.c
	$(CC) -g -c $< $(FLAGS) $(INC) -o $@

obj_folder :
	mkdir -p obj

clean :
	make -C libft/ clean
	rm -f $(OBJS)
	rm -rf obj

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
