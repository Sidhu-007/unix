#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int pipefd[2];
    if (pipe(pipefd) == -1) { perror("pipe"); return 1; }
    pid_t pid = fork();
    if (pid == -1) { perror("fork"); return 1; }
    if (pid == 0) {
        close(pipefd[0]);
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) { perror("dup2"); return 1; }
        close(pipefd[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp ls");
    } else {
        close(pipefd[1]);
        if (dup2(pipefd[0], STDIN_FILENO) == -1) { perror("dup2"); return 1; }
        close(pipefd[0]);
        execlp("wc", "wc", "-l", (char *)NULL);
        perror("execlp wc");
    }
    return 1;
}
