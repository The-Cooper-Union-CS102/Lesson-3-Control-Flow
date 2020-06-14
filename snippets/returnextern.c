#include <stdio.h>

int A = 0;
int B = 0;
int C = 0;

void find_triple(int max) {
    int a, b, c;
    for (a = 1; a <= max; a++) {
        for (b = 1; b <= max; b++) {
            for (c = 1; c <= max; c++) {
                if (a*a + b*b == c*c) {
                    A = a;
                    B = b;
                    C = c;
                    return;
                }
            }
        }
    }
}

int main() {
    find_triple(13);
    printf("Triple: %d %d %d\n", A, B, C);
}
