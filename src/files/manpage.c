#include <stdio.h>

void manpage(char *filename, char *projectname) {
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp,
          ".\\\" Manpage for %s.\n"
          "\n"
          ".TH %s 8 \"<date>\" \"0.0.1\" \"%s man page\"\n"
          "\n"
          ".SH NAME\n"
          "\n"
          ".SH SYNOPSIS\n"
          "\n"
          ".SH DESCRIPTION\n"
          "\n"
          ".SH OPTIONS\n"
          "\n"
          ".SH SEE ALSO\n"
          "\n"
          ".SH BUGS\n"
          "\n"
          ".SH AUTHOR\n",
          projectname, projectname, projectname );
  fclose(fp);
}
