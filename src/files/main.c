#include <stdio.h>

void mainfile(char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp, "#include <stdio.h>\n"
              "#include <stdlib.h>\n"
              "#include <unistd.h>\n"
              "#include <string.h>\n"
              "\n"
              "int main (int argc, char *argv[])\n"
              "{\n"
              "\n"
              "\n"
              "\n"
              "  return 0;\n"
              "}");
  fclose(fp);
}
