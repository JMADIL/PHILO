CC := cc

CFLAGS := -Werror -Wextra -Wall #-fsanitize=thread -g

RM := rm -f

NAME := philo

SRCS := main.c philo_utils.c validate_args.c begin_simulation.c end_simulation.c cycle.c cleanup.c \
		utils.c\


OBJS := ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} philo.h
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re