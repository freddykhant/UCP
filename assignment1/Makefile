CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = snake.o terminal.o random.o
EXEC = program

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

snake.o: snake.c terminal.h random.h
	$(CC) -c snake.c $(CFLAGS)

terminal.o: terminal.c terminal.h
	$(CC) -c terminal.c -Wall $(CFLAGS)

random.o: random.c random.h
	$(CC) -c random.c $(CFLAGS)

clean: 
	rm -f $(EXEC) $(OBJ)
