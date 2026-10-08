#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>

int main() {

   printf("_POSIX_VERSION constant: %ld\n", (long)_POSIX_VERSION);

    if (sysconf(_SC_ASYNCHRONOUS_IO) > 0)
        printf("POSIX Asynchronous I/O supported\n");

    if (sysconf(_SC_BARRIERS) > 0)
        printf("POSIX Barriers supported\n");

    if (pathconf("/", _PC_CHOWN_RESTRICTED) > 0)
        printf("POSIX Chown Restricted supported\n");

    if (sysconf(_SC_CLOCK_SELECTION) > 0)
        printf("POSIX Clock Selection supported\n");

    if (sysconf(_SC_CPUTIME) > 0)
        printf("POSIX CPU Time supported\n");

    if (sysconf(_SC_FSYNC) > 0)
        printf("POSIX Fsync supported\n");

    if (sysconf(_SC_IPV6) > 0)
        printf("POSIX IPv6 supported\n");

    if (sysconf(_SC_JOB_CONTROL) > 0)
        printf("POSIX Job Control supported\n");

    if (sysconf(_SC_MAPPED_FILES) > 0)
        printf("POSIX Mapped Files supported\n");

    if (sysconf(_SC_MEMLOCK) > 0)
        printf("POSIX Memlock supported\n");

    if (sysconf(_SC_MEMLOCK_RANGE) > 0)
        printf("POSIX Memlock Range supported\n");

    if (sysconf(_SC_MEMORY_PROTECTION) > 0)
        printf("POSIX Memory Protection supported\n");

    if (sysconf(_SC_MESSAGE_PASSING) > 0)
        printf("POSIX Message Passing supported\n");

    if (sysconf(_SC_MONOTONIC_CLOCK) > 0)
        printf("POSIX Monotonic Clock supported\n");

    if (pathconf("/", _PC_NO_TRUNC) > 0)
        printf("POSIX No Truncation supported\n");

    if (sysconf(_SC_PRIORITIZED_IO) > 0)
        printf("POSIX Prioritized I/O supported\n");

    if (sysconf(_SC_PRIORITY_SCHEDULING) > 0)
        printf("POSIX Priority Scheduling supported\n");

    if (sysconf(_SC_RAW_SOCKETS) > 0)
        printf("POSIX Raw Sockets supported\n");

    if (sysconf(_SC_REALTIME_SIGNALS) > 0)
        printf("POSIX Real-time Signals supported\n");

    if (sysconf(_SC_SAVED_IDS) > 0)
        printf("POSIX Saved IDs supported\n");

    if (sysconf(_SC_SEMAPHORES) > 0)
        printf("POSIX Semaphores supported\n");

    if (sysconf(_SC_SHARED_MEMORY_OBJECTS) > 0)
        printf("POSIX Shared Memory Objects supported\n");

    if (sysconf(_SC_SHELL) > 0)
        printf("POSIX Shell supported\n");

    if (sysconf(_SC_SPAWN) > 0)
        printf("POSIX Spawn supported\n");

    if (sysconf(_SC_SPIN_LOCKS) > 0)
        printf("POSIX Spin Locks supported\n");

    if (sysconf(_SC_SPORADIC_SERVER) > 0)
        printf("POSIX Sporadic Server supported\n");

    if (sysconf(_SC_SYNCHRONIZED_IO) > 0)
        printf("POSIX Synchronized I/O supported\n");

    if (sysconf(_SC_THREAD_ATTR_STACKADDR) > 0)
        printf("POSIX Thread Attribute Stack Address supported\n");

    if (sysconf(_SC_THREAD_ATTR_STACKSIZE) > 0)
        printf("POSIX Thread Attribute Stack Size supported\n");

    if (sysconf(_SC_THREAD_CPUTIME) > 0)
        printf("POSIX Thread CPU Time supported\n");

    if (sysconf(_SC_THREAD_PRIO_INHERIT) > 0)
        printf("POSIX Thread Priority Inheritance supported\n");

    if (sysconf(_SC_THREAD_PRIO_PROTECT) > 0)
        printf("POSIX Thread Priority Protect supported\n");

    if (sysconf(_SC_THREAD_PRIORITY_SCHEDULING) > 0)
        printf("POSIX Thread Priority Scheduling supported\n");

    if (sysconf(_SC_THREAD_PROCESS_SHARED) > 0)
        printf("POSIX Thread Process Shared supported\n");

    if (sysconf(_SC_THREAD_ROBUST_PRIO_INHERIT) > 0)
        printf("POSIX Thread Robust Priority Inheritance supported\n");

    if (sysconf(_SC_THREAD_ROBUST_PRIO_PROTECT) > 0)
        printf("POSIX Thread Robust Priority Protect supported\n");

    if (sysconf(_SC_THREAD_SAFE_FUNCTIONS) > 0)
        printf("POSIX Thread Safe Functions supported\n");

    if (sysconf(_SC_THREAD_SPORADIC_SERVER) > 0)
        printf("POSIX Thread Sporadic Server supported\n");

    if (sysconf(_SC_THREADS) > 0)
        printf("POSIX Threads supported\n");

    if (sysconf(_SC_TIMEOUTS) > 0)
        printf("POSIX Timeouts supported\n");

    if (sysconf(_SC_TIMERS) > 0)
        printf("POSIX Timers supported\n");

    if (sysconf(_SC_TRACE) > 0)
        printf("POSIX Trace supported\n");

    if (sysconf(_SC_TYPED_MEMORY_OBJECTS) > 0)
        printf("POSIX Typed Memory Objects supported\n");

#ifdef _POSIX_VDISABLE
    printf("POSIX VDISABLE value: %ld\n", (long)_POSIX_VDISABLE);
#endif

    if (sysconf(_SC_V6_ILP32_OFF32) > 0)
        printf("POSIX V6 ILP32 OFF32 supported\n");

    if (sysconf(_SC_V6_ILP32_OFFBIG) > 0)
        printf("POSIX V6 ILP32 OFFBIG supported\n");

    if (sysconf(_SC_V6_LP64_OFF64) > 0)
        printf("POSIX V6 LP64 OFF64 supported\n");

    if (sysconf(_SC_V6_LPBIG_OFFBIG) > 0)
        printf("POSIX V6 LPBIG OFFBIG supported\n");

    if (sysconf(_SC_V7_ILP32_OFF32) > 0)
        printf("POSIX V7 ILP32 OFF32 supported\n");

    if (sysconf(_SC_V7_ILP32_OFFBIG) > 0)
        printf("POSIX V7 ILP32 OFFBIG supported\n");

    if (sysconf(_SC_V7_LP64_OFF64) > 0)
        printf("POSIX V7 LP64 OFF64 supported\n");

    if (sysconf(_SC_V7_LPBIG_OFFBIG) > 0)
        printf("POSIX V7 LPBIG OFFBIG supported\n");

    return 0;
}
