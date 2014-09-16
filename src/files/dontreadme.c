#include <stdio.h>

void dontreadme(char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp, "just an empty file for git to add the build folder");
  fclose(fp);
}
