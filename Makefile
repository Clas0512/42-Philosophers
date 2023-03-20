all :
		 gcc -pthread main.c threads_start.c utils.c actions.c -o philo -fsanitize=thread