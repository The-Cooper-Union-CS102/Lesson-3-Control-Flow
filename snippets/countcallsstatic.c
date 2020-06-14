#include <stdio.h>

int countCalls() {
    static int counter = 0;
    counter += 1;
    return counter;
}

int main() {
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
}
