#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readme(char *filename, char *projectpath) {


  char underscore[200];
  int n=strlen(projectpath);

  strcpy(underscore, "=");
  while (n-- > 0)
  strcat(underscore, "=");

  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp, "%s:\n"
              "%s\n\n"
              "<description>\n\n"
              "Usage:\n"
              "------\n\n"
              "<usage>\n\n"
              "Installation:\n"
              "-------------\n\n"
              "<installation>",
          projectpath, underscore
          );
  fclose(fp);
}
