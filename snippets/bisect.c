#include <stdio.h>

int main() {
    double square = 2;
    double precision = 1e-3;
    double lowerBound = 0;
    double upperBound = square;
    double currentGuess = lowerBound;
    while (upperBound - lowerBound > precision) {
        printf("Guessing: %g...  ", currentGuess);
        if (currentGuess*currentGuess > square) {
            printf("That was too big\n");
            upperBound = currentGuess;
            currentGuess = (currentGuess + lowerBound) / 2.0;
        } else {
            printf("That was too small\n");
            lowerBound = currentGuess;
            currentGuess = (currentGuess + upperBound) / 2.0;
        }
        printf("Now I know the answer is between %g and %g\n",
               lowerBound, upperBound);
    }
    printf("The square root of %g is about %g\n", square, currentGuess);
}
