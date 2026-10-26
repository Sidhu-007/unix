#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <mqueue.h>
#include <signal.h>

#define QUEUE_NAME "/my_queue"
#define MAX_MSG_SIZE 256

int sender_process(void)
{
    mqd_t mqd = mq_open(QUEUE_NAME, O_WRONLY);
    char msg[MAX_MSG_SIZE];
    if (mqd == (mqd_t)-1) { perror("mq_open"); return 1; }
    printf("Sender process: Enter a message (type 'exit' to quit):\n");
    while (1) {
        if (fgets(msg, sizeof(msg), stdin) == NULL)
            strcpy(msg, "exit\n");
        if (mq_send(mqd, msg, strlen(msg), 0) == -1) {
            perror("mq_send"); mq_close(mqd); return 1;
        }
        if (strcmp(msg, "exit\n") == 0 || strcmp(msg, "exit") == 0)
            break;
    }
    mq_close(mqd);
    return 0;
}

int receiver_process(void)
{
    mqd_t mqd = mq_open(QUEUE_NAME, O_RDONLY);
    char msg[MAX_MSG_SIZE + 1];
    ssize_t bytes_read;
    if (mqd == (mqd_t)-1) { perror("mq_open"); return 1; }
    printf("Receiver process: Waiting for messages...\n");
    while (1) {
        bytes_read = mq_receive(mqd, msg, MAX_MSG_SIZE, NULL);
        if (bytes_read == -1) {
            perror("mq_receive"); mq_close(mqd); return 1;
        }
        msg[bytes_read] = '\0';
        printf("Received message: %s", msg);
        if (strcmp(msg, "exit\n") == 0 || strcmp(msg, "exit") == 0)
            break;
    }
    mq_close(mqd);
    return 0;
}

int main(void)
{
    struct mq_attr attr = {0};
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_MSG_SIZE;
    mqd_t mqd = mq_open(QUEUE_NAME, O_CREAT | O_EXCL | O_RDWR, 0600, &attr);
    if (mqd == (mqd_t)-1) { perror("mq_open"); return 1; }
    setbuf(stdout, NULL);
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork"); mq_close(mqd); mq_unlink(QUEUE_NAME); return 1;
    }
    mq_close(mqd);
    if (pid == 0)
        return receiver_process();
    int result = sender_process();
    if (result != 0) kill(pid, SIGTERM);
    int status;
    if (waitpid(pid, &status, 0) == -1) { perror("waitpid"); result = 1; }
    else if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) result = 1;
    if (mq_unlink(QUEUE_NAME) == -1) { perror("mq_unlink"); result = 1; }
    return result;
}
