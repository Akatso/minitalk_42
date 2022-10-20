NAME = server client
NAME_BONUS = server_bonus client_bonus

SRC_SRV = server.c
SRC_CLT = client.c
SRC_SRV_BONUS = server_bonus.c
SRC_CLT_BONUS = client_bonus.c

SRC_UTL = ft_utils1.c \
		  ft_utils2.c

OBJ_SRV = $(SRC_SRV:%.c=%.o)
OBJ_CLT = $(SRC_CLT:%.c=%.o)
OBJ_SRV_BONUS = $(SRC_SRV_BONUS:%.c=%.o)
OBJ_CLT_BONUS = $(SRC_CLT_BONUS:%.c=%.o)

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

bonus : $(NAME_BONUS)

server_bonus : $(OBJ_SRV_BONUS) $(OBJ_UTL)
	$(CC) $(CFLAGS) -o server_bonus $(OBJ_SRV_BONUS) $(OBJ_UTL)

client_bonus : $(OBJ_CLT_BONUS) $(OBJ_UTL)
	$(CC) $(CFLAGS) -o client_bonus $(OBJ_CLT_BONUS) $(OBJ_UTL)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_SRV)
	rm -rf $(OBJ_CLT)
	rm -rf $(OBJ_UTL)
	rm -rf $(OBJ_SRV_BONUS)
	rm -rf $(OBJ_CLT_BONUS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean $(NAME)
rebonus : fclean $(NAME_BONUS)

.PHONY : clean fclean re all
