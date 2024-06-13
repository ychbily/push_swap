CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=undefined

SRCS = main.c ./src/free_error.c ./src/ft_atoi.c ./src/ft_split.c ./src/ft_strjoin.c ./src/push_op.c \
		./src/push_swap_algo_utils.c ./src/push_swap_algo_utils_2.c ./src/push_swap_algo.c \
		./src/reverse_rotate_op.c ./src/rotate_op.c ./src/stack_init.c ./src/swap_op.c ./src/tiny_sort.c \
		./src/utils.c ./src/utils_2.c ./src/push_swap_algo_utils_3.c ./src/handle_args.c ./src/median.c
		
BSRC = checker_bonus.c ./src/checker_utils_bonus.c ./src/ft_split.c ./src/stack_init.c ./src/free_error.c ./src/ft_atoi.c ./src/ft_strjoin.c \
	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	./src/utils.c ./src/utils_2.c ./src/reverse_rotate_op.c ./src/rotate_op.c ./src/push_op.c ./src/swap_op.c \
	./src/handle_args.c 
		
OBJS = $(SRCS:.c=.o)
BOBJ = $(BSRC:.c=.o)
NAME = push_swap
BNAME = checker_bonus
COMPILATION_STARTED := .compilation_started
HEADERS = includes/push_swap.h includes/get_next_line.h includes/checker_bonus.h

all: $(NAME)
	@rm -f $(COMPILATION_STARTED)
	@echo "\n(꩜ ᯅ ꩜;)⁭ ⁭⁭ 📦 All Done. 📦  (꩜ ᯅ ꩜;)⁭ ⁭\n⁭"

$(NAME): $(OBJS)
	@echo "\n\n⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆"
	@echo "⁺｡˚        Linking $@...        ｡⁺⋆"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "⁺｡˚   Linking of $@ complete.   ｡⁺⋆"
	@echo "⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆"

$(BNAME): $(BOBJ)
	@echo "\n\n⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆"
	@echo "⁺｡˚        Linking $@...        ｡⁺⋆"
	@$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)
	@echo "⁺｡˚   Linking of $@ complete.   ｡⁺⋆"
	@echo "⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆"

%.o: %.c $(HEADERS)
	@if [ ! -f $(COMPILATION_STARTED) ]; then \
		echo "\nCompilation starting: "; \
		touch $(COMPILATION_STARTED); \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@ && printf "⌛"

clean:
	@echo "Cleaning object files ..."
	@rm -f $(OBJS) $(BOBJ) $(COMPILATION_STARTED)
	@echo "▄︻デ══━一💥 Clean complete. 💥一━══デ︻▄"

fclean: clean
	@echo "\n⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖"
	@echo "\nRemoving binaries..."
	@rm -rf $(NAME) $(BNAME)
	@echo "▄︻デ══━一💥 Full clean complete. 💥一━══デ︻▄"

re: fclean all

bonus: $(BNAME)
	@rm -rf $(COMPILATION_STARTED)x				
	@echo "\n(꩜ ᯅ ꩜;)⁭ ⁭⁭ 📦 All Done. 📦  (꩜ ᯅ ꩜;)⁭ ⁭⁭\n"

.PHONY: clean
