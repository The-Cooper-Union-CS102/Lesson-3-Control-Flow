#include <stdio.h>

int func()
{
    int myVar = 1;
    return myVar;
}

int main() {
    int myVar = 0;
    printf("%d\n", myVar);
    printf("%d\n", func());
    printf("%d\n", myVar);
}
