// adopted source code from https://lkml.org/lkml/2019/9/18/794

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define RDPRU ".byte 0x0f, 0x01, 0xfd"
#define RDPRU_ECX_MPERF 0
#define RDPRU_ECX_APERF 1

void read_aperf_mperf(unsigned long long *aval, unsigned long long *mval) {
        unsigned long low_a, high_a;
        unsigned long low_m, high_m;

        asm volatile(RDPRU
                : "=a" (low_a), "=d" (high_a)
                : "c" (RDPRU_ECX_APERF));

        asm volatile(RDPRU
                : "=a" (low_m), "=d" (high_m)
                : "c" (RDPRU_ECX_MPERF));

        *aval = ((low_a) | (high_a) << 32);
        *mval = ((low_m) | (high_m) << 32);
}

int main(int argc, const char **argv) {

        unsigned long long last_a, last_m, curr_a, curr_m;
        bool start = true;

        for (;;) {
                last_a = curr_a;
                last_m = curr_m;

                read_aperf_mperf(&curr_a, &curr_m);

                if (start) {
                        start = false;
                } else {
                        printf("%llu,%llu,%.2f\n", curr_a-last_a, curr_m-last_m, (double) (curr_a-last_a) / (double) (curr_m-last_m));
                }

                sleep(1);
        }

        return 0;
}
