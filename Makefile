all :
		gcc -o server -L. server.c ft_utils1.c ft_utils2.c
		gcc -o client -L. client.c ft_utils1.c ft_utils2.c
