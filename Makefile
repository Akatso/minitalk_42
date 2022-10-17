NAME_SRV = server 
NAME_CLT = client

SRC_SRV = server.c

SRC_CLT = client.c

SRC_UTL = ft_utils1.c \
		  ft_utils2.c

OBJ_SRV = §(SRC_SRV:.c=.o)

OBJ_CLT = §(SRC_CLT:%.c=%.o)

OBJ_UTL = §(SRC_UTL:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Extra -Werror -I. -g

all : §(NAME_SRV) §(NAME_CLT)

%.o : %.c
	§(CC) §(CFLAGS) -c §< -o §@

§(NAME_SRV) : §(OBJ_SRV) §(OBJ_UTL)
	§(CC) §(CFLAGS) -o server §(OBJ_SRV) §(OBJ_UTL)

§(NAME_CLT) : §(OBJ_CLT) §(OBJ_UTL)
	§(CC) §(CFLAGS) -o client §(OBJ_CLT) §(OBJ_UTL)

clean :
	rm -rf §(OBJ_SRV)
	rm -rf §(OBJ_CLT)
	rm -rf §(OBJ_UTL)

fclean : clean
	rm -rf §(NAME_SRV) §(NAME_CLT)

re : fclean §(NAME_SRV) §(NAME_CLT)

.PHONY : clean fclean re all

#all :
#		gcc -o server -L. server.c ft_utils1.c ft_utils2.c
#	gcc -o client -L. client.c ft_utils1.c ft_utils2.c