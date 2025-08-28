CC := cc

CFLAGS := -Werror -Wextra -Wall -pthread -O2
DEBUG_FLAGS := -fsanitize=thread -g -DDEBUG
RELEASE_FLAGS := -O2 -DNDEBUG

# Detect if we want debug mode
ifdef DEBUG
    CFLAGS += $(DEBUG_FLAGS)
else
    CFLAGS += $(RELEASE_FLAGS)
endif

RM := rm -f

NAME := philo

SRCS := main.c philo_utils.c validate_args.c begin_simulation.c end_simulation.c cycle.c cleanup.c \
		utils.c\


OBJS := ${SRCS:.c=.o}

all: ${NAME}

debug: 
	$(MAKE) DEBUG=1

${NAME}: ${OBJS} philo.h
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all debug clean fclean re

.PHONY: all clean fclean re