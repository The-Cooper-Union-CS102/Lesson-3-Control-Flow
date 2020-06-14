#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))

int main() {
    int i = 0;
    int j = 0;
    int m = max(++i, ++j);
    printf("%d %d %d\n", i, j, m);
}
