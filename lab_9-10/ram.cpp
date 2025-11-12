#include "ram.h"
#include <iostream>
#include <string>

using namespace std;

Ram::Ram(int newCount, string newName, float newGigabyteSize): Circuit(newCount, newName) {
    if (newGigabyteSize <= 0) {
        cout << "Gigabyte size must be >= 0!" << endl;
        return;
    }

    gigabyteSize = newGigabyteSize;
};

void Ram::showInfo () {
    cout << "Ram " << name << " has " << transistorCount << " transistors and " << gigabyteSize << " GB" << endl; 
}

Ram::~Ram() {
    cout << "Boom Boom!" << endl;
}