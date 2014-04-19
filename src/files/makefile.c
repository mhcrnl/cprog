#include <stdio.h>

void makefile(char *filename, char *projectname) {
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp, "# variables\n"
              "\n"
              "CC = gcc\n"
              "OBJ = build/code.o\n"
              "CFLAGS = -Wall\n"
              "DEPS =\n"
              "\n"
              "# make\n"
              "\n"
              "%s: $(OBJ)\n"
              "\t$(CC) $(CFLAGS) -o $@ $(OBJ)\n"
              "\n"
              "build/%%.o: src/%%.c $(DEPS)\n"
              "\t$(CC) $(CFLAGS) -c $< -o $@\n"
              "\n"
              "# make install\n"
              "\n"
              "install:\n"
              "\tinstall -m 0755 -o root -g root %s /usr/bin/%s\n",
              projectname, projectname, projectname);
  fclose(fp);
}
