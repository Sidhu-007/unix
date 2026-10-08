#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 3) {
      fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

    if (rename(argv[1], argv[2]) == -1) {
       perror("mv");
       exit(EXIT_FAILURE);
    }

    printf("Moved '%s' to '%s'\n", argv[1], argv[2]);
    return 0;
}
