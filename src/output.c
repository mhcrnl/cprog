#include <stdio.h>

void help() {
  printf( "\n"
          "The program is creating the basic folderstructure for a C project\n"
          "\n"
          "Known options are:\n"
          "-s | --silent    No output\n"
          "-h | --help      Display's this help\n"
          "-v | --version   Shows program version\n"
          "\n");
}

void version() {
  printf( "\n"
          "The program version is 0.0.1\n"
          "\n");
}
