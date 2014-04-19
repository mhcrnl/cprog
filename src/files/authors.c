#include <stdio.h>

void authors(char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp, "<yournamehere>");
  fclose(fp);
}
