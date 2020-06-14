#include <stdio.h>


int uparrow(int a, int b, int n) {
    int i;
    int res = 0;
    for (i = 0; i < b; i++) {
        if (i == 0) {
            res = a;
        } else {
            res = uparrow(res, a, n-1);
        }
    }
    return res;
}

int main() {
    printf("starting\n");
    int res = uparrow(2, 2, 3);
    printf("%d\n", res);
}
