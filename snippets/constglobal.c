#include <stdio.h>

int COUNTER = 0;

int countCalls() {
    COUNTER += 1;
    return COUNTER;
}

int main() {
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
}
