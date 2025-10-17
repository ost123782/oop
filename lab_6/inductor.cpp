#include <iostream>
#include <tuple>
#include <array>
#include <cmath>
#include "inductor.h"

using namespace std;

#define PI 3.14159

void Inductor::printInfo() const {
    cout << "------------------------" << endl;
    cout << "Inductor Details:" << endl;
    cout << "  Inductance: " << inductance << " H" << endl;
    cout << "  Resistance: " << resistance << " Ohm" << endl;
    cout << "  Turns count: " << turnsCount << endl;
    cout << "------------------------" << endl;
}

float Inductor::getResistance() const {
    return resistance;
}

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