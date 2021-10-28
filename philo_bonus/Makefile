FLAG = -Wall -Wextra -Werror

LIB = philo.a

NAME = philo

SRC = 	main.c \
		atoi.c \
		init.c \
		utils.c \
		process.c \
		isDead.c 


OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(LIB): $(OBJ)
	@ar rc $(LIB) $(OBJ)
	@echo "$(LIB) created"
	@ranlib $(LIB)
	@echo "$(LIB) indexed"

$(NAME): $(LIB)
	@gcc $(FLAG) $(LIB) -o $(NAME)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAG) -c $^ -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(LIB)
	@echo "$(LIB) deleted"
	@rm -f $(NAME)
	@echo "$(NAME) deleted"


re: fclean all

.PHONY: all clean fclean re