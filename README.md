# UNIX System Programming Lab: Programs 1-5

Based on programs 1-5 in the supplied NMIT 21ISG64, 2021 scheme lab manual.
All files use UTF-8 text, Unix LF line endings, and a final newline.

| File | Program |
| --- | --- |
| p1_limits.c | System limits, page size, hostname and working directory |
| p2_posix_options.c | POSIX version and supported configuration options |
| p3a_mv.c | Move/rename a file using rename() |
| p3b_grep.c | Print input lines containing a literal substring |
| p4_links.c | Create hard and symbolic links and show link counts |
| p5_file_lock.c | Lock and unlock a file using fcntl() |

## Upload to GitHub and clone

1. Extract lab-programs.zip.
2. Create a GitHub repository named lab-programs.
3. Use Add file > Upload files to upload the CONTENTS of the extracted folder to the repository root. Upload the C files, README.md, Makefile, .gitignore and .gitattributes. Do not upload only the ZIP.
4. Commit the files.
5. On your Linux machine, replace YOUR_USERNAME below:

```bash
git clone https://github.com/YOUR_USERNAME/lab-programs.git
cd lab-programs
make
```

Requires GCC and Make. On Ubuntu, if missing:

```bash
sudo apt install build-essential git
```

Compile a single program without Make:

```bash
gcc -std=c11 -Wall -Wextra p1_limits.c -o p1_limits
./p1_limits
```

## Run

Programs 1 and 2:

```bash
./p1_limits
./p2_posix_options
```

Programs 3-5: use a fresh demo directory so existing files are not overwritten:

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

The links program creates hard_link and sym_link in the current directory. Running it again there fails if those names already exist. The lock program opens or creates testfile.txt; run it in a fresh demo directory for clean output.

## Small corrections and scope

- Program 2 checks runtime option support instead of reporting every defined macro as supported. It covers all the option names listed in the manual. The special VDISABLE character value is printed separately; file-dependent options are checked for `/`. Output varies by system and may differ from the manual's screenshot.
- Program 1 reserves space for the hostname terminator. A limit printed as -1 may be indeterminate or unavailable; this simple example retains the manual's direct sysconf/pathconf output.
- Program 3a is the manual's rename-based demonstration: it does not implement cross-filesystem moves or all mv options. A destination file can be replaced by rename().
- Program 3b removes an unnecessary fixed-size pattern copy. It matches literal substrings, not regular expressions, and retains the manual's 1024-byte input buffer (use short text lines).
- Program 4 removes unused variables and uses the correct link-count print conversion. stat() follows a symbolic link; lstat() inspects the symbolic link itself.
- Program 5 initializes flock structures and uses sizeof to calculate write lengths without null terminators. fcntl locks are advisory: the process holding the lock can still write. This example locks, writes and unlocks immediately; it does not demonstrate two-process contention.

## Unix line endings

.gitattributes enforces LF line endings for text files, including after git clone on Windows. EOF is the end of a file; LF is the Unix line-ending format.

## Clean compiled executables

```bash
make clean
```
