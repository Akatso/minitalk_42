NAME = server client

SRC_SRV = server.c

SRC_CLT = client.c

SRC_UTL = ft_utils1.c \
		  ft_utils2.c

OBJ_SRV = $(SRC_SRV:%.c=%.o)

OBJ_CLT = $(SRC_CLT:%.c=%.o)

OBJ_UTL = $(SRC_UTL:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -g

all : $(NAME)

server : $(OBJ_SRV) $(OBJ_UTL)
	$(CC) $(CFLAGS) -o server $(OBJ_SRV) $(OBJ_UTL)

client : $(OBJ_CLT) $(OBJ_UTL)
	$(CC) $(CFLAGS) -o client $(OBJ_CLT) $(OBJ_UTL)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_SRV)
	rm -rf $(OBJ_CLT)
	rm -rf $(OBJ_UTL)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean re all
