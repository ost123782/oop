#include <iostream>
#include <array>
#include "inductor.h"

using namespace std;

void findAndPrintByResistance(const array<unique_ptr<Inductor>, 3>& inductors, float targetResistance) {
    cout << endl << ">>> Searching for inductors with resistance = " << targetResistance << " Ohm..." << endl;
    bool found = false;

    for (const auto& inductor : inductors) {
        if (inductor && inductor->getResistance() == targetResistance) {
            inductor->printInfo();
            found = true;
        }
    }

    if (!found) {
        cout << "No inductors found with resistance " << targetResistance << " Ohm." << endl;
    }
}

int main() {
    array<unique_ptr<Inductor>, 3> myInductors;

    cout << "Creating 3 inductor objects..." << endl;
    for (int i = 0; i < 3; ++i) {
        cout << endl << "Enter data for inductor #" << i + 1 << endl;
        myInductors[i] = make_unique<Inductor>();
    }

    cout << endl << "--- All inductors created ---" << endl;
    for(const auto& ind : myInductors) {
        ind->printInfo();
    }

    float resistanceToFind;
    cout << endl << "Enter the resistance value to search for: ";
    cin >> resistanceToFind;

    findAndPrintByResistance(myInductors, resistanceToFind);
    
    findAndPrintByResistance(myInductors, -99.99);

    cout << endl << "Program finished." << endl;
    return 0;
}
