#include <stdio.h>

int find_triple(int max) {
    int a, b, c;
    for (a = 1; a <= max; a++) {
        for (b = 1; b <= max; b++) {
            for (c = 1; c <= max; c++) {
                if (a*a + b*b == c*c) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main() {
    int triple_exists = find_triple(13);
    printf("Triple exists? %d\n", triple_exists);
}
