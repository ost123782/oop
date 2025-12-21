#include "inductor.h"

template <typename T>
Inductor<T>::Inductor(T newInductance, T newResistance, int newTurnsCount) {
    if (newInductance < 0 || newResistance < 0 || newTurnsCount < 0) {
        cout << "Values must be >= 0!" << endl;
    }
    inductance = newInductance;
    resistance = newResistance;
    turnsCount = newTurnsCount;
}

template <typename T>
Inductor<T>::~Inductor() {
    cout << "Boom! (Generic)" << endl;
}

template <typename T>
void Inductor<T>::setInductance(T newInductance) {
    if (newInductance < 0) {
        cout << "Not valid value" << endl;
        return;
    }
    inductance = newInductance;
}

template <typename T>
void Inductor<T>::printInfo() {
    cout << "------------------------" << endl;
    cout << "Inductor (Generic) Details:" << endl;
    cout << "  Inductance: " << inductance << " H" << endl;
    cout << "  Resistance: " << resistance << " Ohm" << endl;
    cout << "  Turns count: " << turnsCount << endl;
    cout << "------------------------" << endl;
}

Inductor<double>::Inductor(double newInductance, double newResistance, int newTurnsCount) {
    if (newInductance < 0 || newResistance < 0 || newTurnsCount < 0) {
        cout << "Values must be >= 0!" << endl;
    }
    inductance = newInductance;
    resistance = newResistance;
    turnsCount = newTurnsCount;
}

Inductor<double>::~Inductor() {
    cout << "Boom! (Double)" << endl;
}

void Inductor<double>::printInfo() {
    cout << "------------------------" << endl;
    cout << "Inductor (Double Specialization) Details:" << endl;
    cout << scientific << setprecision(2);
    cout << "  Inductance: " << inductance << " H" << endl;
    cout << "  Resistance: " << resistance << " Ohm" << endl;
    cout << "  Turns count: " << turnsCount << endl;
    cout << defaultfloat;
    cout << "------------------------" << endl;
}

template <typename T>
Inductor<T*>::Inductor(T* newInductance, T* newResistance, int newTurnsCount) {
    if (*newInductance < 0 || *newResistance < 0 || newTurnsCount < 0) {
        cout << "Values must be >= 0!" << endl;
    }
    inductance = newInductance;
    resistance = newResistance;
    turnsCount = newTurnsCount;
}

template <typename T>
Inductor<T*>::~Inductor() {
    cout << "Boom! (Pointer)" << endl;
}

template <typename T>
void Inductor<T*>::printInfo() {
    cout << "------------------------" << endl;
    cout << "Inductor (Pointer Specialization) Details:" << endl;
    cout << "  Inductance: " << *inductance << " H" << endl;
    cout << "  Resistance: " << *resistance << " Ohm" << endl;
    cout << "  Turns count: " << turnsCount << endl;
    cout << "------------------------" << endl;
}

template class Inductor<int>;
template class Inductor<int*>;