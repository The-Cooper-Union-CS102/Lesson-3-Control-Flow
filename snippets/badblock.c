#include <stdio.h>

int main() {
    {
        int i = 5;
        printf("%d\n", i);
    }
    {
        double i = 3.14;
        printf("%g\n", i);
        {
            printf("%c\n", i);
            char i = 'i';
        }
        printf("%g\n", i);
    }
}
