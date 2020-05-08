#include <stdio.h>

int main() {
    int countDownFrom = 100;
    while (countDownFrom >= 0) {
        printf("%d, ", countDownFrom);
        countDownFrom--;
    }
    printf("Lift off!\n");
}
