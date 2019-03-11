all:
	gcc -std=gnu99 -c display.c
	gcc -std=gnu99 -c client.c
	gcc -std=gnu99 -c tools.c
	gcc -std=gnu99 -c server.c
	gcc -std=gnu99 -c func.c
	gcc -std=gnu99 -c func2.c
	gcc display.o tools.o client.o -lpthread  -o ATM
	gcc server.o -lpthread func.o func2.o -o Server
