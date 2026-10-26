# UNIX System Programming Lab

C programs for experiments 1–10 of the **NMIT 21ISG64 Lab Manual, 2021 Scheme**.

## Programs

| No. | File | Description |
| --- | --- | --- |
| 1 | `p1_limits.c` | System limits, page size, hostname and working directory |
| 2 | `p2_posix_options.c` | POSIX version and supported configuration options |
| 3(a) | `p3a_mv.c` | Move or rename a file using `rename()` |
| 3(b) | `p3b_grep.c` | Print lines containing a literal substring |
| 4 | `p4_links.c` | Create hard and symbolic links and display link counts |
| 5 | `p5_file_lock.c` | Lock and unlock a file using `fcntl()` |
| 6 | `6.c` | Inter-process communication using POSIX message queues |
| 7(a) | `7a.c` | Execute two commands using a pipe |
| 7(b) | `7b.c` | Communication using a named pipe (FIFO) |
| 8 | `8.c` | Zombie, double-fork, orphan and parent–child demonstrations |
| 9 | `9.c` | Signal handling using `sigaction()` and blocking `SIGINT` |
| 10 | `10.c` | Synchronize threads using a semaphore |

## Requirements

Use Linux with GCC installed.

On Ubuntu or Debian:

```bash
sudo apt install build-essential git
```

## Compile

Run these commands in the folder containing the source files:

```bash
gcc -Wall -Wextra p1_limits.c -o p1_limits
gcc -Wall -Wextra p2_posix_options.c -o p2_posix_options
gcc -Wall -Wextra p3a_mv.c -o p3a_mv
gcc -Wall -Wextra p3b_grep.c -o p3b_grep
gcc -Wall -Wextra p4_links.c -o p4_links
gcc -Wall -Wextra p5_file_lock.c -o p5_file_lock
gcc -Wall -Wextra 6.c -o p6 -lrt
gcc -Wall -Wextra 7a.c -o p7a
gcc -Wall -Wextra 7b.c -o p7b
gcc -Wall -Wextra 8.c -o p8
gcc -Wall -Wextra 9.c -o p9
gcc -Wall -Wextra 10.c -o p10 -pthread
```

## Run

### Programs 1 and 2

```bash
./p1_limits
./p2_posix_options
```

### Programs 3–5

Use a fresh directory for the file demonstrations:

```bash
mkdir demo
cd demo

printf 'Hello UNIX\nHello Linux\nUNIX lab\n' > sample.txt

../p3b_grep UNIX < sample.txt
../p3a_mv sample.txt moved.txt
../p4_links moved.txt

ls -li moved.txt hard_link sym_link

../p5_file_lock
cat testfile.txt

cd ..
```

For another run, use a different demo directory. Program 4 fails if `hard_link` or `sym_link` already exists.

### Programs 6–10

Run each program separately:

| Program | Command | Instructions |
| --- | --- | --- |
| 6 | `./p6` | Enter messages; type `exit` on its own line to finish |
| 7(a) | `./p7a` | Displays the line count of `ls -l` output |
| 7(b) | `./p7b` | Displays the message received by the child |
| 8 | `./p8` | Runs the process demonstrations in about 11 seconds |
| 9 | `./p9` | Blocks Ctrl+C; use Ctrl+\ to stop |
| 10 | `./p10` | Five threads increment the shared value to 5 |

## Important Notes

- Programs follow the manual's approach with corrections for errors and resource cleanup.
- System limits, process IDs and thread execution order may vary.
- Program 3(a) uses `rename()` and does not support cross-filesystem moves. An existing destination may be replaced.
- Program 3(b) matches literal substrings, not regular expressions. Use short input lines.
- Program 5 uses advisory file locks. The process holding the lock can still write.
- Program 6 waits for the receiver before removing the message queue.
- Program 7(b) follows the manual's parent–child example. These are related processes, although the question mentions unrelated processes.
- Program 9 registers a handler but blocks `SIGINT`; the handler cannot run for that signal while it remains blocked.
- If program 6 or 7(b) reports `File exists`, check whether another process is using the queue or FIFO before removing a stale object.
- Source files use UTF-8 text and Unix LF line endings.

## GitHub Setup

1. Upload the source files and `README.md` to your repository.
2. Upload the extracted files, not only the ZIP.
3. Clone the repository on your Linux machine:
