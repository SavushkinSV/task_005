CFLAGS=-Werror -Wextra -Wall 
CC=gcc
FSAN=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector

all: house


house: house.c
	$(CC) $(CFLAGS)house.c -o ../bin/house

travel: house.c
	$(CC) $(CFLAGS)house.c -o ../bin/travel

morse: house.c
	$(CC) $(CFLAGS)house.c -o ../bin/morse

clean:
	rm -rf *.o *.out

check:
	clang-format -style='{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}' -i *.c
	# clang-format -style='{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}' -i *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	# valgrind --tool=memcheck --leak-check=yes ../bin/house