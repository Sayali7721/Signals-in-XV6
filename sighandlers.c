#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "x86.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "syscall.h"
#include "mmu.h"

int
if_kern_sig(int signum)
{
  if( signum == SIGKILL || signum ==  SIGSTOP || signum == SIGCONT || signum == SIG_DFL)
    return 1;
  return 0;
}
int
sigdefault(void)
{
    struct proc *p = myproc();
    if (p == 0)
        return -1;
    p->killed = 1;
    return 0;
}
int
sigstop(void)
{
    struct proc *p = myproc();
    if (p == 0 || p->state == SLEEPING)
        return -1;
    p->stopped = 1;
    p->state = RUNNABLE;
    return 0;
}

int
sigcontinue(void)
{
    struct proc *p = myproc();
    if (p == 0 || p->state == RUNNING)
        return -1;
    p->stopped = 0;
    p->state = RUNNING;
    return 0;
}
int
sigterminate(void)
{
  struct proc *p = myproc();
  if(p == 0)
    return -1;
  if(p->state == SLEEPING)
    p->state = RUNNABLE;
  p->killed = 1;
  return 0;
}
void
kernel_handler(struct proc *p, int signum){
  if(signum == SIG_DFL){
    sigdefault();
    return;
  }
  else if(signum == SIGSTOP || signum == SIGTSTP || signum == SIGTTOU || signum == SIGTTOU){
    sigstop();
    return;
  }
  else if(signum == SIGCONT){
    sigcontinue();
    return;
  }
  else if(signum == SIGTERM){
    sigterminate();
    return;
  }
}
void
user_handler(struct proc *p, int signum){
  sighandler_t sighandle = p->handlers[signum];
  p->oldmask = p->signalmask;
  memmove(p->backup, p->tf, sizeof(struct trapframe));
  p->signalmask = p->masks[signum];
  p->tf->esp -= 4;
  *((uint*)p->tf->esp) = p->tf->eip;
  p->tf->esp -= 4;
  *((uint*)p->tf->esp) = signum;
  p->tf->esp -= 4;
  *((uint*)p->tf->esp) = p->sigretadd;
  p->tf->eip = sighandle;
}
void
check_pending_signals(struct proc *p){
  for (int signum = 0; signum <= NSIG; signum++)
  {
    if(if_kern_sig(signum))
      kernel_handler(p, signum);
    else{
      user_handler(p, signum);
      return;
    }
  }
}
void
if_pending_sig(void)
{
  struct proc *p = myproc();
  int i;
  for(i = 0; i < NSIG; i++){
    if (p->pending_signals[i])
      break;
  }
  if(i == NSIG || p == 0)
    return;
  check_pending_signals(p);
}