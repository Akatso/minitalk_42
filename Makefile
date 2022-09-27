all :
		gcc -o server -L. server.c ft_utils.c  
		gcc -o client -L. client.c ft_utils.c
