CC=gcc217
CFLAGS=-Wall -Wextra -g

all: sampleft sampleftM

clean:
	rm -f *.o sampleft

clobber: clean
	rm -f *~

sampleft: ft.o ft_client.o checkerFT.o dynarray.o nodeFT.o path.o
	$(CC) ft.o ft_client.o checkerFT.o dynarray.o nodeFT.o path.o -o sampleft

sampleftM: ftM.o ft_clientM.o checkerFTM.o dynarrayM.o nodeFTM.o pathM.o
	gcc217m -Wall -Wextra -g ftM.o ft_clientM.o checkerFTM.o dynarrayM.o nodeFTM.o pathM.o -o sampleftM

ft.o: ft.c ft.h a4def.h
	$(CC) $(CFLAGS) -c ft.c

ftM.o: ft.c ft.h a4def.h
	gcc217m -Wall -Wextra -g -c ft.c -o ftM.o

ft_client.o: ft_client.c ft.h a4def.h
	$(CC) $(CFLAGS) -c ft_client.c

ft_clientM.o: ft_client.c ft.h a4def.h
	gcc217m -Wall -Wextra -g -c ft_client.c -o ft_clientM.o

checkerFT.o: checkerFT.c checkerFT.h
	$(CC) $(CFLAGS) -c checkerFT.c

checkerFTM.o: checkerFT.c checkerFT.h
	gcc217m -Wall -Wextra -g -c checkerFT.c -o checkerFTM.o

dynarray.o: dynarray.c dynarray.h
	$(CC) $(CFLAGS) -c dynarray.c

dynarrayM.o: dynarray.c dynarray.h
	gcc217m -Wall -Wextra -g -c dynarray.c -o dynarrayM.o

nodeFT.o: nodeFT.c nodeFT.h
	$(CC) $(CFLAGS) -c nodeFT.c

nodeFTM.o: nodeFT.c nodeFT.h
	gcc217m -Wall -Wextra -g -c nodeFT.c -o nodeFTM.o

path.o: path.c path.h
	$(CC) $(CFLAGS) -c path.c

pathM.o: path.c path.h
	gcc217m -Wall -Wextra -g -c path.c -o pathM.o