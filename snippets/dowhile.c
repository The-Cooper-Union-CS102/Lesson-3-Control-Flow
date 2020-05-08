#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = -1;
    do {
        n = rand();
    }
    while (n > 100);
    printf("Random number between 0 and 500: %d\n", n);
}
