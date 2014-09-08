#include <stdio.h>

void gitignore(char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp,
          "# Object files\n"
          "*.o\n"
          "*.ko\n"
          "*.obj\n"
          "*.elf\n"
          "\n"
          "# Libraries\n"
          "*.lib\n"
          "*.a\n"
          "\n"
          "# Shared objects (inc. Windows DLLs)\n"
          "*.dll\n"
          "*.so\n"
          "*.so.*\n"
          "*.dylib\n"
          "\n"
          "# Executables\n"
          "*.exe\n"
          "*.out\n"
          "*.app\n"
          "*.i*86\n"
          "*.x86_64\n"
          "*.hex\n"
          "\n"
          "# Editor files\n"
          "*~\n"
          "\\#*\\#\n"
          );
  fclose(fp);
}
