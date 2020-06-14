#include <stdio.h>

#define forever while (1)

int main() {
    int i = 0;
    forever {
        if (i < 3) {
            i++;
            printf("%d\n", i);
        } else {
            break;
        }
    }
}
