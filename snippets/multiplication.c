#include "addition.h"

int multiply(int x, int y) {
    // Overly complicated way of multiplying
    int r = 0;
    for (int i = 0; i < y; i++) {
        r = add(x, r);
    }
    return r;
}
