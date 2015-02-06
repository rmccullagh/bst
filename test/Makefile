CCFLAGS = -g -Wall -Wextra

default: search_test.o bst.o
	gcc $(CCFLAGS) -o search_test bst.o search_test.o
search_test.o: search_test.c
	gcc $(CCFLAGS) -c search_test.c
bst.o: ../bst.c
	gcc $(CCFLAGS) -c ../bst.c
clean:
	rm -f *.o *.exe
