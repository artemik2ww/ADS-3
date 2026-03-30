// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    unsigned int mx = num;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            if (num > (UINT64_MAX - 1) / 3) {
                return mx;
            }
            num = 3 * num + 1;
        }

        if (num > mx) {
            mx = num;
        }
    }
    return mx;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int l = 1;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            if (num > (UINT64_MAX - 1) / 3) {
                return 0;
            }
            num = 3 * num + 1;
        }
        l++;
    }
    return l;
}

unsigned int seqCollatz(unsigned int* maxlen,
    uint64_t lbound,
    uint64_t rbound) {
    unsigned int blen = 0;
    uint64_t bnum = 0;
    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int curl = collatzLen(num);
        if (curl > blen) {
            blen = curl;
            bnum = num;
        }
    }
    *maxlen = blen;
    return (unsigned int)bnum;
}
