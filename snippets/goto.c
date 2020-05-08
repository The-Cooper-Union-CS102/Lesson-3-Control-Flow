#include <stdio.h>

int main() {
    int a, b, c, max;
    max = 13;
    for (a = 1; a <= max; a++) {
        for (b = 1; b <= max; b++) {
            for (c = 1; c <= max; c++) {
                if (a*a + b*b == c*c) {
                    goto found;
                }
            }
        }
    }
found:
    printf("%d %d %d\n", a, b, c);
}
