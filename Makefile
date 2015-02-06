objects = main.o bst.o
CCFLAGS = -Wall -Wextra -Wpedantic

main : $(objects)
		cc $(CCFLAGS) -o bst $(objects)

.PHONY : clean
clean:
	rm -f bst $(objects)
