#include <stdio.h>

int main() {
    int n;
    for (n = 0; n < 50; n++) {
        if (n % 3 == 0) {
            continue;
        }
        int square = n*n;
        if (square > 500) {
            continue;
        }
        int cube = n*n*n;
        if (cube % 5 == 0) {
            continue;
        }
        printf("%d\n", n);
    }
}
