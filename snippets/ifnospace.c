#include <stdio.h>

int main() {
    int grade = 75;
    int credits = 2;
    if (credits != 0) { if (grade >= 90) {
    printf("No problem!\n"); } else if (grade >= 80) {
    printf("Not bad.\n"); } else if (grade >= 70) {
    if (credits < 3) { printf("All right...\n"); } else {
    printf("Not good.\n"); } } else { printf("Panic!\n");
    } } else { printf("Who cares?\n");}
}
