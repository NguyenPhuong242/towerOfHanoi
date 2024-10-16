#include <iostream>
#include "hanoi.h"
#include "animation.h"

using namespace std;

int main(){
    int numDisks;

    cout << "Enter the number of disks: ";
    cin >> numDisks;

    if(numDisks < 1){
        cout << "Invalid number of disks." << endl;
        return 1;
    }

    // Initialize the rods for animation
    initializeRods(numDisks);

    // Perform the Tower of Hanoi solution
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;

}