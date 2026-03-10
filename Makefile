SRC=coders/src/codexion.c coders/src/ft_atol.c\
	coders/src/dongle_init.c coders/src/coder_init.c coders/src/parsing.c\
	coders/src/init.c coders/src/time.c coders/src/codexion.c\
	coders/src/free_data.c coders/src/heap.c coders/src/check_simulation.c\
	coders/src/getters.c
OBJ=$(SRC:.c=.o)
CFLAGS=-g3 -Wall -Wextra -Werror -pthread
NAME=codexion

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ -I coders/include/

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS) -I coders/include/

clean:
	rm -rf coders/src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
