CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC_LIB = budget_lib.c input_utils.c file_io.c

# interactive CLI app
app: main.c $(SRC_LIB)
	$(CC) $(CFLAGS) main.c $(SRC_LIB) -o budget_app.out

# automated unit‑test executable (no keyboard input)
test: test_budget.c $(SRC_LIB)
	$(CC) $(CFLAGS) test_budget.c $(SRC_LIB) -o budget_test.out
	./budget_test.out

clean:
	rm -f *.out *.txt
