#include <stdio.h>

int fib(n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int result;
    int n;
    for (n = 0; n <= 15; n++) {
        result = fib(n);
        printf("fib(%d) = %d\n", n, result);
    }
}
