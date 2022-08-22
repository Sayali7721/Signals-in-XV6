#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"

int main(){
    int choice, num;
    printf(1, "Press 1 to test kill signal\n");
    printf(1, "Press 2 to test stop signal\n");
    printf(1, "Press 3 to test continue signal\n");
    printf(1, "Press 4 to test alarm signal\n");
    printf(1, "Press 5 to test sigprocmask\n");
    printf(1, "Press 6 to test sigaction\n");
    printf(1, "Press 7 to test pause signal\n");
    printf(1, "Press 8 to test termination signal\n");

    do {
        printf(1, "Enter your choice --> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                test_sigkill();
                break;
            case 2:
                test_sigstop();
                break;
            case 3:
                test_sigcont();
                break;
            case 4:
                test_sigalarm();
                break;
            case 5:
                test_sigprocmask();
                break;
            case 6:
                test_sigaction();
                break;
            case 7:
                test_pause();
                break;
            case 8:
                test_sigterm();
                break;
        }
    } while(choice <= 8);
    exit();
}

void test_sigkill(void)
{
    printf(1, "Testing SIGKILL..\n");
    int pid = fork();
    if(pid == 0){
        sigkill(pid, SIGKILL);
        printf(1, "SIGKILL test failed..\n");
    }
    else {
        wait();
        printf(1, "SIGKILL test passed..\n");
    }
}

void test_sigprocmask(void)
{
    printf(1, "Testing sigprocmask..\n");
    int mask = 9221;
    int oldmask = sigprocmask(mask);
    if(mask == sigprocmask(oldmask)){
        printf(1, "Sigprocmask test passed..\n");
    } else {
        printf(1, "Sigprocmask test failed..\n");
    }
}

void test_sigaction(void)
{
    printf(1, "Testing sigaction..\n");
    struct sigaction *newaction;
    newaction->sigmask = 92;
    sighandler_t newhandle;
    newaction->sh = newhandle;
}

void test_sigalarm(void)
{
    printf(1, "Testing sigalarm..\n");
}

void test_pause(void)
{
    printf(1, "Testing pause signal..\n");
}

void test_sigstop(void)
{
    printf(1, "Testing SIGSTOP..\n");
    int pid = fork();
    if(pid == 0){
        sigkill(pid, SIGSTOP);
        printf(1, "SIGSTOP test failed..\n");
    }
    else {
        wait();
        printf(1, "SIGSTOP test passed..\n");
    }
}

void test_sigcontinue(void)
{
    printf(1, "Testing SIGSTOP..\n");
    int pid = fork();
    if(pid == 0){
        sigkill(pid, SIGSTOP);
        sigkill(pid, SIGCONT);
        printf(1, "SIGCONT test failed..\n");
    }
    else {
        wait();
        sigkill(pid, SIGCONT);
        printf(1, "SIGCONT test passed..\n");
    }
}

void test_sigterm(void)
{
    printf(1, "Testing SIGTERM..\n");
}