#include <stdio.h>

int main() {
    int countDownFrom;
    for (countDownFrom = 100; countDownFrom >= 0; countDownFrom--) {
        printf("%d, ", countDownFrom);
    }
    printf("Lift off!\n");
}
