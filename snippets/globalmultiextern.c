#include <stdio.h>
//#include "sineextern.c"

// Engineer's approximation of PI
const double PI = 3.0;

double sinDegrees(double x);

int main() {
    printf("%g\n", sinDegrees(45));
    printf("%g\n", PI);
}
