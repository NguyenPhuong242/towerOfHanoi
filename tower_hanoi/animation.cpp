#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

const int MAX_DISKS = 64;
int count = 0;

// Rods to hold the disks
vector<int> rodA, rodB, rodC;

// Function to print the current state of the rods
void printRods(){
    // Avoid unnecessary calls to system("clear") in every iteration, only when necessary
    static int lastHash = 0;
    int currentHash = rodA.size() + rodB.size() + rodC.size(); // check to avoid excessive calls to system("clear")

    if (lastHash != currentHash) {
        (void) system("clear");  // Cast to void to avoid warning
        lastHash = currentHash;
    }

    // Display the rods
    cout << "Rod A: ";
    for (int i = rodA.size() - 1; i >= 0; i--){
        cout << rodA[i] << " ";
    }
    cout << endl;

    cout << "Rod B: ";
    for (int i = rodB.size() - 1; i >= 0; i--){
        cout << rodB[i] << " ";
    }
    cout << endl;

    cout << "Rod C: ";
    for (int i = rodC.size() - 1; i >= 0; i--){
        cout << rodC[i] << " ";
    }
    cout << endl;

    this_thread::sleep_for(chrono::milliseconds(300)); // sleep for 100 milliseconds
}

// initialize the rods with the number of disks
void initializeRods(int numDisks) {
    rodA.clear();
    rodB.clear();
    rodC.clear();
    // Add the disks to rod A
    for (int i = numDisks; i > 0; i--) {
        rodA.push_back(i);
    }

    printRods();
}

// Move the top disk from the 'from_rod' to the 'to_rod'
void moveDisk(int disk, char fromRod, char toRod) {
    vector<int> *from, *to;
    // Determine the 'from' rod
    switch (fromRod) {
        case 'A':
            from = &rodA;
            break;
        case 'B':
            from = &rodB;
            break;
        case 'C':
            from = &rodC;
            break;
    }

    // Determine the 'to' rod
    switch (toRod) {
        case 'A':
            to = &rodA;
            break;
        case 'B':
            to = &rodB;
            break;
        case 'C':
            to = &rodC;
            break;
    }

    if (!from->empty()) {
        int movedDisk = from->back();
        from->pop_back();
        to->push_back(movedDisk);

        // Display the rods
        cout << "Move disk " << movedDisk << " from rod " << fromRod << " to rod " << toRod << endl;
        printRods();
        count++;
        cout << "Number of moves: " << count << endl;
        
    }
}