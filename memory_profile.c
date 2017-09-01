#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

static void handler(int signal_number, siginfo_t* info, void* p) {
    (void)signal_number;
    (void)info;
    (void)p;
    exit(0);
}

int main()
{
	void *A, *B, *C;
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    sigemptyset(&action.sa_mask);
    action.sa_sigaction = handler;
    action.sa_flags = SA_RESTART | SA_SIGINFO;

    sigaction(SIGQUIT, &action, NULL);
    sigaction(SIGINT, &action, NULL);
    printf("usage: LD_PRELOAD=/xxx/libmemusage.so MEMUSAGE_OUTPUT=profile.dat program\n");
    printf("use Ctrl+C, or kill -2 %d, or kill -3 %d to exit\n", getpid(), getpid());

	A = malloc(0x100 - 8);
	B = malloc(0x100 - 8);
	C = malloc(0x80 - 8);
    free(B);

    getchar();

	return 0;
}
