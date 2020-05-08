#include <stdio.h>

int main() {
    int n, m, max, product;
    max = 13;
    for (m = 1; m <= max; m++) {
        for (n = 1; n <= max; n++) {
            product = m*n;
            printf("%4d", product);
        }
        printf("\n");
    }
}
