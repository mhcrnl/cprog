# variables

CC = gcc
OBJ = build/main.o build/output.o build/files/authors.o build/files/gnu.o build/files/main.o build/files/makefile.o build/files/changelog.o build/files/configure.o build/files/dontreadme.o build/file/readme.o build/files/manpage.o
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

clean:
	rm -f cprog
	find build -name *.o -exec rm -f {} \;
