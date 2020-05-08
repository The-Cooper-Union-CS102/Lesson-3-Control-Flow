#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int five = add(2, 3);
    printf("five = %d\n", five);
}
