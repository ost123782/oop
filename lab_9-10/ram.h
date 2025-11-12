#ifndef RAM_H

#define RAM_H

#include "circuit.h"
#include <iostream>
#include <string>


using namespace std;

class Ram: public Circuit {
    public:
        void showInfo();
        Ram(int newCount, string newName, float newGigabyteSize);
        ~Ram();
    private:
        float gigabyteSize;
};

#endif