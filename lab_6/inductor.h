#ifndef INDUCTOR_H

#define INDUCTOR_H

#include <iostream>
using namespace std;

class Inductor {
public:
    void setInductance(float _inductance);
    void setReactiveResistance(int frequency);
    float getReactiveResistance();
    void getMaximumFrequency();
    void printInfo() const;
    float getResistance() const;
    ~Inductor();

    Inductor() {
        bool isValid = false;
        while (!isValid) {
            cout << "Enter inductance (H), resistance (Ohm), count of turns: ";
            cin >> inductance >> resistance >> turnsCount;

            if (inductance < 0 || resistance < 0 || turnsCount < 0) {
                cout << "Inductor is not valid! Please re-enter." << endl;
                continue;
            }

            isValid = true;
        }
    }

private:
    float inductance;
    float resistance;
    int turnsCount;
    float reactiveResistance;
    float findReactiveResistance(int frequency);
    tuple<int, float> findMultiplier(float value);
};

#endif