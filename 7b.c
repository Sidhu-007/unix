#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#define FIFO_FILE "/tmp/myfifo"

int main(void)
{
    char buf[256];
    int fd, result = 0, status;
    if (mkfifo(FIFO_FILE, 0600) == -1) { perror("mkfifo"); return 1; }
    pid_t pid = fork();
    if (pid == -1) { perror("fork"); unlink(FIFO_FILE); return 1; }
    if (pid == 0) {
        fd = open(FIFO_FILE, O_RDONLY);
        if (fd == -1) { perror("open"); return 1; }
        ssize_t n = read(fd, buf, sizeof(buf) - 1);
        if (n == -1) { perror("read"); close(fd); return 1; }
        buf[n] = '\0';
        printf("Child received: %s\n", buf);
        close(fd);
        return 0;
    }
    fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1) { perror("open"); kill(pid, SIGTERM); result = 1; }
    else {
        if (write(fd, "Hello from parent!", sizeof("Hello from parent!"))
            != (ssize_t)sizeof("Hello from parent!")) { perror("write"); result = 1; }
        close(fd);
    }
    if (waitpid(pid, &status, 0) == -1) { perror("waitpid"); result = 1; }
    else if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) result = 1;
    if (unlink(FIFO_FILE) == -1) { perror("unlink"); result = 1; }
    return result;
}
