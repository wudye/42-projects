




NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
OBJ_DIR = objs/

SRCS =  $(wildcard *.c)
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ}
	$(CC) $(CFLAGS) $^ -o $@

re : fclean all


clean:
	$(RM) $(OBJ_DIR)

fclean:
	$(RM) $(NAME) 

.PHONY: clean fclean re all