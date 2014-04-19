# variables

CC = gcc
OBJ = build/code.o build/output.o build/files/authors.o build/files/gnu.o build/files/license.o build/files/main.o build/files/makefile.o build/files/changelog.o build/files/configure.o
CFLAGS = -Wall
DEPS =

# make

cprog: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

build/%.o: src/%.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# make install

install:
	install -m 0755 -o root -g root cprog /usr/bin/cprog
