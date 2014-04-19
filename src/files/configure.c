#include <stdio.h>

void configure(char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp, "#!/bin/sh\n"
              "\n"
              "PATH=/bin:/usr/bin\n"
              "\n"
              "echo Checking dependencies::\n"
              "echo "";\n"
              "\n"
              "echo looking for make:;\n"
              "which make > /dev/null;\n"
              "if [ $? -ne 0 ]\n"
              "then\n"
              "  echo make not found;\n"
              "  exit 1;\n"
              "else\n"
              "  echo found ... $(which make);\n"
              "fi\n"
              "\n"
              "echo looking for gcc:;\n"
              "which gcc > /dev/null;\n"
              "if [ $? -ne 0 ]\n"
              "then\n"
              "  echo gcc not found;\n"
              "  exit 2;\n"
              "else\n"
              "  echo found ... $(which gcc);\n"
              "fi\n"
              "echo looking for install:;\n"
              "\n"
              "which install > /dev/null;\n"
              "if [ $? -ne 0 ]\n"
              "then\n"
              "  echo install not found;\n"
              "  exit 3;\n"
              "else\n"
              "  echo found ... $(which install);\n"
              "fi\n");
  fclose(fp);
}
