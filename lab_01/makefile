CFLAGS = -std=c99 -Wall -Werror -pedantic
CLFLAGS = main test *.o *.gch 
OBJ = main

ifeq ($(mode), test)
	OBJ = test
endif

ifeq ($(mode), drmemory)
	CFLAGS += -m32 -ggdb
endif

ifeq ($(mode), debug)
	CFLAGS += -g3 -DNDEBUG
endif
 
$(OBJ): functions.o $(OBJ).o
	gcc $(CFLAGS) $^ -o $@

%.o: %.c *.h
	gcc $(CFLAGS) -c $^

clean:
	rm -rf $(CLFLAGS)

