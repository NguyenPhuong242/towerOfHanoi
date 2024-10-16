#include <iostream>
#include "hanoi.h"
#include "animation.h"

// Tower of Hanoi recursive algorithm
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        moveDisk(1, source, destination);  // Call moveDisk with disk number 1
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);
    moveDisk(n, source, destination);  // Move the nth disk
    towerOfHanoi(n - 1, auxiliary, destination, source);
}
