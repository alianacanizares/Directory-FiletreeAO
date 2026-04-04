CC=gcc217
CFLAGS=-Wall -Wextra -g

all: sampleft

clean:
	rm -f *.o sampleft

clobber: clean
	rm -f *~

sampleft: ft.o ft_client.o checkerFT.o dynarray.o nodeFT.o path.o
	$(CC) ft.o ft_client.o checkerFT.o dynarray.o nodeFT.o path.o -o sampleft


ft.o: ft.c ft.h a4def.h
	$(CC) $(CFLAGS) -c ft.c

ft_client.o: ft_client.c ft.h a4def.h
	$(CC) $(CFLAGS) -c ft_client.c

checkerFT.o: checkerFT.c checkerFT.h
	$(CC) $(CFLAGS) -c checkerFT.c

dynarray.o: dynarray.c dynarray.h
	$(CC) $(CFLAGS) -c dynarray.c

nodeFT.o: nodeFT.c nodeFT.h
	$(CC) $(CFLAGS) -c nodeFT.c

path.o: path.c path.h
	$(CC) $(CFLAGS) -c path.c