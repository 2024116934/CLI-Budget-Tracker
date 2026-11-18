CC = gcc
CFLAGS = -Wall -g

main: main.c budget_lib.c budget_lib.h input_utils.c input_utils.h file_io.c file_io.h
	$(CC) $(CFLAGS) main.c budget_lib.c input_utils.c file_io.c -o budget

run: main
	./budget

clean:
	rm -f budget *.o records.txt
