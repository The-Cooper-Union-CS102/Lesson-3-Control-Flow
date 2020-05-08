#include <stdio.h>

int addTwo(int num) {
    return num + 2;
}

int main() {
    int three = addTwo(1);
    printf("three = %d\n", three);
}
