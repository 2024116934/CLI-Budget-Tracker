CC = gcc
CFLAGS = -Wall -g

main: main.c budget_lib.c budget_lib.h input_utils.c input_utils.h
	$(CC) $(CFLAGS) main.c budget_lib.c input_utils.c -o budget

run: main
	./budget

clean:
	rm -f budget *.o
