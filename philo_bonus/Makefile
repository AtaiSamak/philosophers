FLAG = -Wall -Wextra -Werror

LIB = philo.h

NAME = philo_bonus

SRC = 	main.c \
		atoi.c \
		init.c \
		utils.c \
		process.c \
		isDead.c 


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(FLAG) $(OBJ) -o $(NAME)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAG) -c $^ -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"


re: fclean all

.PHONY: all clean fclean re