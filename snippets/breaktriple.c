#include <stdio.h>

int main() {
    int a, b, c, max;
    int found = 0;
    max = 13;
    for (a = 1; a <= max; a++) {
        for (b = 1; b <= max; b++) {
            for (c = 1; c <= max; c++) {
                if (a*a + b*b == c*c) {
                    found = 1;
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }
    printf("%d %d %d\n", a, b, c);
}
