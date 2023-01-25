all: client.o server.o helpers.c
	stty -icanon
	gcc  client.o server.o helpers.c -o programaTrab -lpthread

helpers.o: helpers.c
	gcc helpers.c -c

server: server.o helpers.c
	stty -icanon
	gcc server.o helpers.c -o server -lpthread

server.o: server.c
	gcc server.c -c server -lpthread

runServer:
	./server

client: client.o helpers.c
	stty -icanon
	gcc client.o helpers.c -o client -lpthread

client.o: client.c
	gcc client.c -c client -lpthread

runClient:
	./client

clean:
	rm -rf programaTrab *.o
run:
	./programaTrab