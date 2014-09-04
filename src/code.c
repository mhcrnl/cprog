#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void help();
void version();
void authors(char *filename);
void changelog(char *filename);
void configure(char *filename);
void gnu(char *filename);
void license(char *filename);
void mainfile(char *filename);
void makefile(char *filename, char *projectname);

int main (int argc, char *argv[])
{

  int arg=1;
  int optionsilent=1;

  int counter, count, argposition[argc];
  int maxarg = 2;

  for (counter=1;counter<argc;counter++)
    if ((strcmp(argv[counter], "-h") == 0) || (strcmp(argv[counter], "--help") == 0)) {
      help();
      exit(0);
    }

  for (counter=1;counter<argc;counter++)
    if ((strcmp(argv[counter], "-v") == 0) || (strcmp(argv[counter], "--version") == 0)) {
      version();
      exit(0);
    }

  for (counter=1; counter<argc; counter++)
    argposition[counter] = 0;

  for (counter=1;counter<argc;counter++) {
    if ((argv[counter][0] == '-') && (argv[counter][1] != '-'))
      for (count = 0; count < strlen(argv[counter]); count++) {
        if (argv[counter][count] == 's') {
          optionsilent = 0;
          if (count == 1)
            maxarg += 1;
        }
        argposition[counter] = 1;
      }
    if (strcmp(argv[counter], "--silent") == 0) {
      optionsilent = 0;
      maxarg += 1;
      argposition[counter] = 1;
    }
  }

  if (argc < maxarg || argc > maxarg ) {
    printf("Usage: %s <programname>\n", argv[0]);
    exit(1);
  }

  for (counter=1; counter<argc; counter++)
    if (argposition[counter] == 0)
      arg = counter;

  if (argv[arg][0] == '-') {
    printf("Error: expected option but value is unknown\n");
    exit(1);
  }

  char dirname[5][300];

  sprintf(dirname[1] ,"%s", argv[arg]);
  sprintf(dirname[2] ,"%s/src", argv[arg]);
  sprintf(dirname[3] ,"%s/build", argv[arg]);
  sprintf(dirname[4] ,"%s/man", argv[arg]);

  if (optionsilent == 1)
    printf("Creating:\n");

  for (count=1;count<5;count++) {
    if (mkdir(dirname[count], 0775) != 0) {
      perror("Error");
      exit(1);
    }
    if (optionsilent == 1)
      printf("%s\n", dirname[count]);
  }

  char filename[300];

  sprintf(filename ,"%s/src/code.c", argv[arg]);
  mainfile(filename);
  if (optionsilent == 1)
    printf("%s\n", filename);

  sprintf(filename ,"%s/CHANGELOG", argv[arg]);
  changelog(filename);
  if (optionsilent == 1)
    printf("%s\n", filename);

  sprintf(filename ,"%s/AUTHORS", argv[arg]);
  authors(filename);
  if (optionsilent == 1)
    printf("%s\n", filename);

  sprintf(filename ,"%s/configure", argv[arg]);
  configure(filename);
  chmod(filename, 0775);
  if (optionsilent == 1)
    printf("%s\n", filename);

  sprintf(filename ,"%s/makefile", argv[arg]);
  makefile(filename, argv[arg]);
  if (optionsilent == 1)
    printf("%s\n", filename);

  sprintf(filename ,"%s/LICENSE", argv[arg]);
  gnu(filename);
  if (optionsilent == 1)
    printf("%s\n", filename);

  return 0;
}
