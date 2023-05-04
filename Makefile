NAME	= philo

SRCS	= main.c init.c threads_start.c utils.c actions.c checks.c

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

D_RACE	= -g -fsanitize=thread

all		: $(NAME)

$(NAME)	: $(SRCS)
		@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
		@echo "\x1b[42mCompiled"

D_RACE	:
		@$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(D_RACE)
		@echo "\x1b[38;5;3mData Race Checker is Active"
clean	:
		@rm -rf philo.dSYM

fclean	: clean
		@rm -rf $(NAME)

re		: fclean all
		