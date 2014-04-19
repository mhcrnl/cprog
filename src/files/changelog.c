#include <stdio.h>

void changelog(char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp, "--------\n"
              "0.0.1:\n"
              "\n"
              "\n"
              "--------\n");
  fclose(fp);
}
