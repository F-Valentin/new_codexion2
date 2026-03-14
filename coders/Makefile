SRC=src/codexion.c src/ft_atol.c\
	src/dongle_init.c src/coder_init.c src/parsing.c\
	src/init.c src/time.c src/codexion.c\
	src/free_data.c src/heap.c src/check_simulation.c\
	src/getters.c src/monitor.c src/one_coder.c\
	src/dongle.c src/coder_actions.c src/utils.c\
	src/coder.c
OBJ=$(SRC:.c=.o)
CFLAGS= -g3 -Wall -Wextra -pthread
NAME=codexion

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ -I include/

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS) -I include/

clean:
	rm -rf src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
