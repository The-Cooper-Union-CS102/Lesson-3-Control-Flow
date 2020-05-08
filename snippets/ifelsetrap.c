#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int max;
    int y_was_greater = 0;
    if (x > y)
        max = x;
    else
        max = y;
        y_was_greater = 1;
    printf("y_was_greater? %d\n", y_was_greater);
}
