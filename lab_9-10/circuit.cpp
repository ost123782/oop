#include "circuit.h"
#include <iostream>
#include <string>

using namespace std;

void Circuit::setName(string newName) {
    if (newName.size() == 0) {
        cout << "Name must have at least one character!" << endl;
        return;
    }

    name = newName;
}


void Circuit::setTransistorCount(int newCount) {
    if (newCount <= 0) {
        cout << "Count must be >= 0!" << endl;
        return;
    }

    transistorCount = newCount;
}

void Circuit::showInfo () {
    cout << "Circuit " << name << " has " << transistorCount << " transistors" << endl; 
}

Circuit::Circuit(int newCount, string newName) {
    if (newCount <= 0) {
        cout << "Count must be >= 0!" << endl;
        return;
    }

    transistorCount = newCount;

    if (newName.size() == 0) {
        cout << "Name must have at least one character!" << endl;
        return;
    }

    name = newName;
};
Circuit::~Circuit() {
    cout << "Boom!" << endl;

};