#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = -1;
    while (1) {
        n = rand();
        if (n <= 100) {
            break;
        }
    }
    printf("Random number between 0 and 100: %d\n", n);
}
