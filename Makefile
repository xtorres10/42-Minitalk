CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = server.c client.c

NAME = client server

all : $(NAME)

server : server.c
	$(CC) $(CFLAGS) -o server server.c

client : client.c
	$(CC) $(CFLAGS) -o client client.c

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm $(NAME)

.PHONY : all clean fclean re