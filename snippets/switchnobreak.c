#include <stdio.h>

int main() {
    int countDownFrom = 3;
    switch (countDownFrom) {
        case 5:
            printf("5\n");
        case 4:
            printf("4\n");
        case 3:
            printf("3\n");
        case 2:
            printf("2\n");
        case 1:
            printf("1\n");
        case 0:
            printf("0\n");
        default:
            printf("Lift off!\n");
    return 0;
    }
}
