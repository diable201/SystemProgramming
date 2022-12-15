#include <fenv.h>    
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void fpe_signal_handler(int sig) {
    printf("Floating point exception\n");
    int i = fetestexcept(FE_INVALID);
    if (i & FE_INVALID)
        printf("----> Invalid valued detected\n");

    exit(1);
}
static void fpe_signal_action( int sig, siginfo_t *sip, void *scp )
{
    /* see signal.h for codes */
    int fe_code = sip->si_code;
    if (fe_code == ILL_ILLTRP)
        printf("Illegal trap detected\n");
    else
        printf("Code detected : %d\n",fe_code);
    int i = fetestexcept(FE_INVALID);
    if (i & FE_INVALID)
        printf("---> Invalid valued detected\n");

    abort();
}
void enable_floating_point_exceptions() {
    fenv_t env;
    fegetenv(&env);
    env.__fpcr = env.__fpcr | __fpcr_trap_invalid;
    fesetenv(&env);
    signal(SIGILL,fpe_signal_handler);   
}

int main() {    
    const double x = -1;
    printf("y = %f\n",sqrt(x));    
    enable_floating_point_exceptions();
    printf("y = %f\n",sqrt(x));
}