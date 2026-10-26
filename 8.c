#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t checked_fork(void)
{
    pid_t pid = fork();
    if (pid == -1) { perror("fork"); exit(EXIT_FAILURE); }
    return pid;
}

void create_zombie_process(void)
{
    pid_t pid = checked_fork();
    if (pid == 0) {
        printf("Child exiting (PID: %ld)\n", (long)getpid());
        exit(EXIT_SUCCESS);
    }
    printf("Parent PID: %ld; child PID: %ld\n", (long)getpid(), (long)pid);
    printf("Child will be a zombie until the parent calls waitpid after 5 seconds.\n");
    sleep(5);
    waitpid(pid, NULL, 0);
}

void prevent_zombie_processes(void)
{
    pid_t pid = checked_fork();
    if (pid == 0) {
        pid_t second = checked_fork();
        if (second > 0) {
            printf("First child exiting (PID: %ld)\n", (long)getpid());
            exit(EXIT_SUCCESS);
        }
        sleep(2);
        printf("Grandchild PID: %ld, new parent PID: %ld\n",
               (long)getpid(), (long)getppid());
        exit(EXIT_SUCCESS);
    }
    waitpid(pid, NULL, 0);
    sleep(3);
}

void create_orphan_process(void)
{
    pid_t pid = checked_fork();
    if (pid == 0) {
        pid_t child = checked_fork();
        if (child > 0) {
            printf("Intermediate parent exiting (PID: %ld)\n", (long)getpid());
            exit(EXIT_SUCCESS);
        }
        sleep(2);
        printf("Orphan PID: %ld, adopted by PID: %ld\n",
               (long)getpid(), (long)getppid());
        exit(EXIT_SUCCESS);
    }
    waitpid(pid, NULL, 0);
    sleep(3);
}

void parent_child_scenario(void)
{
    pid_t pid = checked_fork();
    if (pid == 0) {
        printf("child (PID: %ld)\n", (long)getpid());
        exit(EXIT_SUCCESS);
    }
    printf("parent (PID: %ld)\n", (long)getpid());
    waitpid(pid, NULL, 0);
}

int main(void)
{
    setbuf(stdout, NULL);
    puts("Demonstrating zombie process:");
    create_zombie_process();
    puts("\nPreventing zombies with double fork:");
    prevent_zombie_processes();
    puts("\nCreating an orphan process:");
    create_orphan_process();
    puts("\nParent-child scenario:");
    parent_child_scenario();
    return 0;
}
