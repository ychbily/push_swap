CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -ggdb3

SRCS = main.c ./src/free_error.c ./src/ft_atoi.c ./src/ft_split.c ./src/ft_strjoin.c ./src/push_op.c \
		./src/push_swap_algo_utils.c ./src/push_swap_algo_utils_2.c ./src/push_swap_algo.c \
		./src/reverse_rotate_op.c ./src/rotate_op.c ./src/stack_init.c ./src/swap_op.c ./src/tiny_sort.c \
		./src/utils.c ./src/utils_2.c ./src/push_swap_algo_utils_3.c ./src/handle_args.c ./src/median.c \
		
BSRC = checker_bonus.c ./src/ft_split.c ./src/stack_init.c ./src/free_error.c ./src/ft_atoi.c ./src/ft_strjoin.c \
	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c\
	./src/utils.c ./src/utils_2.c ./src/reverse_rotate_op.c ./src/rotate_op.c ./src/push_op.c ./src/swap_op.c \
	./src/handle_args.c 
		
OBJS = $(SRCS:.c=.o)
BOBJ = $(BSRC:.c=.o)
NAME = push_swap
BNAME = checker_bonus

.PHONY:all bonus clean fclean re


all: $(NAME)

%.o: %.c push_swap.h ./includes/get_next_line.h
	$(CC) $(CFLAGS) -c  $< -o $@
	
clean:
	rm -f $(OBJS) $(BOBJ)
	
fclean : clean
	rm -rf $(NAME) $(BNAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re: fclean all

bonus : $(BNAME)

$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

.PHONY: clean
