#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
   if (argc != 2) {
      fprintf(stderr, "Usage: %s <pattern>\n", argv[0]);
      return 1;
   }

    const char *pattern = argv[1];

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), stdin) != NULL) {
      if (strstr(line, pattern) != NULL) {
         printf("%s", line);
      }
    }

    return 0;
}
