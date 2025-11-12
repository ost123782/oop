#ifndef LOGICIC_H

#define LOGICIC_H

#include "circuit.h"
#include <iostream>
#include <string>


using namespace std;

class LogicIc: public Circuit {
    public:
        void showInfo();
        LogicIc(int newCount, string newName, string newPurpose);
        ~LogicIc();
    private:
        string purpose;
};

#endif