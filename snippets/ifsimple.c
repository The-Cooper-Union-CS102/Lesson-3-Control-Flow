#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int max;
    max = y;
    if (x > y)
        max = x;
    printf("max = %d\n", max);
}
