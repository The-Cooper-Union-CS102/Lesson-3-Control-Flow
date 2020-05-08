#include <stdio.h>


int main() {
    /*
    dopey = 0 grumpy = 1 sleepy = 2 happy = 3
    bashful = 4 sneezy = 5 doc = 6
    */
    int dwarf = 3;
    switch (dwarf) {
        case 0:
            printf("...\n");
            break;
        case 1:
            printf("Mark my words, there's trouble a-brewin'.\n");
            break;
        case 2:
            printf("*yawns*\n");
            break;
        case 3:
            printf("I'll take a chance for her.\n");
            break;
        case 4:
            printf("Ohhhhh goooosh.\n");
            break;
        case 5:
            printf("Sink's empty. Hey, someone stole our dishes!\n");
            break;
        case 6:
            printf("We're gonna go down and chase it up, uh uh uh, up...down.\n");
            break;
    return 0;
    }
}
