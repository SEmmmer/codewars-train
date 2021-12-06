#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>


uint64_t hamber(int n) {
    if (n == 1)return 1;
    uint64_t ham = hamber(n - 1) + 1;

    uint64_t array[3] = {2, 3, 5};

    for (uint64_t tmp = ham;; ++tmp, ++ham) {

        int i = 0;
        while (i < 3) {
            if (tmp % array[i] == 0) {
                tmp /= array[i];
            } else {
                i++;
            }
        }

        if (tmp == 1) {
            return ham;
        }
        tmp = ham;
    }
}

int main() {
    printf("%llu\n", hamber(5000));
}