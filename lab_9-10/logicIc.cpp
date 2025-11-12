#include "logicIc.h"
#include <iostream>
#include <string>

using namespace std;

LogicIc::LogicIc(int newCount, string newName, string newPurpose): Circuit(newCount, newName) {
    if (newPurpose.size() == 0) {
        cout << "Purpose length must be at least 1!" << endl;
        return;
    }

    purpose = newPurpose;
};

void LogicIc::showInfo () {
    cout << "Logic IC " << name << " has " << transistorCount << " transistors and " << purpose << " Purpose" << endl; 
}

LogicIc::~LogicIc() {
    cout << "Boom Boom BOOM!" << endl;
}