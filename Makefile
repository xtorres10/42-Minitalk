CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRC = server.c client.c

NAME = client server

all: $(NAME)

server: server.c
	$(CC) $(CFLAGS) -o server server.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $<

clean: $(NAME)
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY : all clean fclean re