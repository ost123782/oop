#ifndef CIRCUIT_H

#define CIRCUIT_H

#include <iostream>
#include <string>

using namespace std;

class Circuit {
    public:
        virtual void showInfo();
        void setTransistorCount(int newCount);
        void setName(string newName);
        Circuit(int newCount, string newName);
        virtual ~Circuit();
    protected:
        int transistorCount;
        string name;

};

#endif
