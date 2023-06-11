CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o draw.o setup.o random.o terminal.o input.o logic.o
EXEC = snake

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c main.h draw.h setup.h random.h terminal.h input.h logic.h
	$(CC) -c main.c $(CFLAGS)

draw.o: draw.c draw.h
	$(CC) -c draw.c $(CFLAGS)

setup.o: setup.c setup.h
	$(CC) -c setup.c $(CFLAGS)

random.o: random.c random.h
	$(CC) -c random.c $(CFLAGS)

terminal.o: terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

input.o: input.c input.h
	$(CC) -c input.c $(CFLAGS)

logic.o: logic.c logic.h
	$(CC) -c logic.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
