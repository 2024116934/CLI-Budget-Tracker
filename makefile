CC = gcc
CFLAGS = -Wall -g

# Main program
MAIN_SRC = main.c budget_lib.c input_utils.c file_io.c
main: $(MAIN_SRC)
	$(CC) $(CFLAGS) $(MAIN_SRC) -o budget

# Unit test program
TEST_SRC = test_budget.c budget_lib.c input_utils.c file_io.c
test: $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o test_budget

run: main
	./budget

runtest: test
	./test_budget

clean:
	rm -f budget test_budget *.o records.txt
