typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;
typedef void (*sighandler_t)(int);
struct sigaction {
  sighandler_t sh;
  int sigmask;
};
