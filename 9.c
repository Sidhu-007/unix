#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signum)
{
    (void)signum;
    const char msg[] = "Received SIGINT\n";
    ssize_t result = write(STDOUT_FILENO, msg, sizeof(msg) - 1);
    (void)result;
}

int main(void)
{
    struct sigaction sa = {0};
    sigset_t old_mask, new_mask;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) { perror("sigaction"); return 1; }
    puts("Signal handler registered for SIGINT (Ctrl+C)");
    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGINT);
    if (sigprocmask(SIG_BLOCK, NULL, &old_mask) == -1) {
        perror("sigprocmask"); return 1;
    }
    if (sigismember(&old_mask, SIGINT)) {
        puts("SIGINT is already present in the signal mask.");
    } else {
        if (sigprocmask(SIG_BLOCK, &new_mask, NULL) == -1) {
            perror("sigprocmask"); return 1;
        }
        puts("Added SIGINT to the signal mask.");
    }
    puts("SIGINT is blocked. Use Ctrl+\\ to quit, or kill -TERM from another terminal.");
    fflush(stdout);
    while (1) sleep(1);
}
