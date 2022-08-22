#define NPROC        64  // maximum number of processes
#define KSTACKSIZE 4096  // size of per-process kernel stack
#define NCPU          8  // maximum number of CPUs
#define NOFILE       16  // open files per process
#define NFILE       100  // open files per system
#define NINODE       50  // maximum number of active i-nodes
#define NDEV         10  // maximum major device number
#define ROOTDEV       1  // device number of file system root disk
#define MAXARG       32  // max exec arguments
#define MAXOPBLOCKS  10  // max # of blocks any FS op writes
#define LOGSIZE      (MAXOPBLOCKS*3)  // max data blocks in on-disk log
#define NBUF         (MAXOPBLOCKS*3)  // size of disk block cache
#define FSSIZE       1000  // size of file system in blocks
// signals
#define NULLO (void*)0
#define NSIG        32
#define SIG_DFL     0
#define SIG_IGN     1
#define SIGINT      2 // program interrupt
#define SIGQUIT     3
#define SIGILL      4 // illegal instruction or stack overflow
#define SIGTRAP     5
#define SIGABRT     6 // self abort
#define SIGBUS      7 // bus error
#define SIGFPE      8 //fatal arithmetic error
#define SIGKILL     9 // immediate program termination
#define SIGUSR1     10 // set aside for user
#define SIGSEGV     11 // segmentation fault
#define SIGCHLD     12 // sent to parent when child stops or terminates
#define SIGPIPE     13 // broken pipe
#define SIGALRM     14 // alarm function
#define SIGTERM     15 // termination signal can be blocked, handled and ignored
#define SIGCONT     18 // to continue a process
#define SIGSTOP     19 // stops a process
#define SIGTSTP     20 // interactive stop can be handled or ignored
#define SIGTTIN     21
#define SIGTTOU     22
#define SIGURG      23 // urgent or out of band data arrives
#define SIGXCPU     24 // cpu time limit exceeded
#define SIGXFSZ     25 // file size limit exceeded
#define SIGVTALRM   26 // virtual time alarm
#define SIGPROF     27 // code profiling facilities
#define SIGWINCH    28 // window size change
#define SIGIO       29 // file descriptor ready for input or output
#define SIGPWR      30
#define SIGSYS      31 // bad system call
#define SIGHUP      32 // hangup signal