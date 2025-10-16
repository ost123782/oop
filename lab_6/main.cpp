#include <iostream>
#include <cmath>
#include <tuple>
#include <array>

using namespace std;

#define PI 3.14159

class Inductor {
public:
    void setInductance(float _inductance);
    void setReactiveResistance(int frequency);
    float getReactiveResistance();
    void getMaximumFrequency();
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

    void printInfo() const {
        cout << "------------------------" << endl;
        cout << "Inductor Details:" << endl;
        cout << "  Inductance: " << inductance << " H" << endl;
        cout << "  Resistance: " << resistance << " Ohm" << endl;
        cout << "  Turns count: " << turnsCount << endl;
        cout << "------------------------" << endl;
    }

    float getResistance() const {
        return resistance;
    }

private:
    float inductance;
    float resistance;
    int turnsCount;
    float reactiveResistance;
    float findReactiveResistance(int frequency);
    tuple<int, float> findMultiplier(float value);
};

void Inductor::setInductance(float _inductance) {
    if (_inductance < 0) {
        cout << "Not valid value " << endl;
        return;
    }
    inductance = _inductance;
}

float Inductor::findReactiveResistance(int frequency) {
    return 2 * PI * frequency * inductance;
}

void Inductor::setReactiveResistance(int frequency) {
    if (frequency < 0) {
        cout << "No valid value";
        return;
    }
    reactiveResistance = findReactiveResistance(frequency);
}

float Inductor::getReactiveResistance() {
    return reactiveResistance;
}

void Inductor::getMaximumFrequency() {
    int maximumResistance = 1 * pow(10, 6);
    float frequency = maximumResistance / (2 * PI * inductance);

    auto [multiplier, fomattedFrequency] = findMultiplier(frequency);

    cout << "Max. frequency for 1 MOhm reactive resistance: " << fomattedFrequency << " * 10^" << multiplier << " Hz" << endl;
}

tuple<int, float> Inductor::findMultiplier(float value) {
    int multiplier = 0;

    if (value == 0) return {0, 0};

    while (value >= 10.0) {
        value /= 10.0;
        multiplier++;
    }
    while (value < 1.0 && value > 0) {
        value *= 10.0;
        multiplier--;
    }

    return {multiplier, value};
}

Inductor::~Inductor() {}

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
