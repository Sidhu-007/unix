#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

  char *filename = argv[1];
  struct stat file_stat;

  if (link(filename, "hard_link") == -1) {
     perror("Error creating hard link");
     exit(EXIT_FAILURE);
  }

  if (symlink(filename, "sym_link") == -1) {
     perror("Error creating symbolic link");
     exit(EXIT_FAILURE);
  }

  if (stat(filename, &file_stat) == -1) {
     perror("Error getting file information");
     exit(EXIT_FAILURE);
  }

  printf("Information about hard link:\n");
  printf("Number of links: %lu\n", (unsigned long)file_stat.st_nlink);

  if (lstat("sym_link", &file_stat) == -1) {
     perror("Error getting symbolic link information");
     exit(EXIT_FAILURE);

    }

    printf("Information about symbolic link:\n");
    printf("Number of links: %lu\n", (unsigned long)file_stat.st_nlink);

    return 0;
}
