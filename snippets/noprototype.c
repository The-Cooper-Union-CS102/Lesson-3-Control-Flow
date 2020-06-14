#include <stdio.h>

int main() {
    int res = add(1.5, 2);
    printf("res = %d\n", res);
}

int add(int a, int b) {
    return a + b;
}
