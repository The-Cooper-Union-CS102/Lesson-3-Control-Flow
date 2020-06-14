#include <stdio.h>

#define square(x) x * x

int main() {
    int s = square(3 + 1);
    printf("%d\n", s);
}
