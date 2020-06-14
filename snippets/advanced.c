#include <stdio.h>

int multiply(a, b) {
    return a * b;
}

int add(a, b) {
    return a + b;
}

int main() {
    int a = 3;
    int b = 4;
    int c = 5;
    int sum = add(add(a, b), multiply(b, c));
    int product = multiply(add(a, b), multiply(b, c));
    printf("product = %d\n", product);
}
