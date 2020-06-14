#include <stdio.h>

int X = 0;
int Y = 0;

void moveLeft() {X--;}
void moveRight() {X++;}
void moveUp() {Y++;}
void moveDown() {Y--;}

int main() {
    moveLeft();
    printf("Position: (%d, %d)\n", X, Y);
    moveUp();
    printf("Position: (%d, %d)\n", X, Y);
    moveRight();
    printf("Position: (%d, %d)\n", X, Y);
    moveDown();
    printf("Position: (%d, %d)\n", X, Y);
}
