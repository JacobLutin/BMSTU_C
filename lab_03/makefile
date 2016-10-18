CFLAGS = -std=c99 -Wall -Werror
CLFLAGS = main test *.o *.gch
OBJ = main

ifeq ($(mode), test)
	OBJ = test
endif

ifeq ($(mode), debug)
	CFLAGS += -DNDEBUG -g3
endif

$(OBJ): list.o $(OBJ).o
	gcc $(CFLAGS) $^ -o $@

%.o: %.c *.h
	gcc $(CFLAGS) -c $^

clean:
	rm -rf $(CLFLAGS)