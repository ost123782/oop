#ifndef INDUCTOR_H
#define INDUCTOR_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Inductor {
private:
    T inductance;
    T resistance;
    int turnsCount;

public:
    Inductor(T newInductance, T newResistance, int newTurnsCount);
    ~Inductor();
    void setInductance(T newInductance);
    void printInfo();
};

template <>
class Inductor<double> {
private:
    double inductance;
    double resistance;
    int turnsCount;

public:
    Inductor(double newInductance, double newResistance, int newTurnsCount);
    ~Inductor();
    void printInfo();
};

template <typename T>
class Inductor<T*> {
private:
    T* inductance;
    T* resistance;
    int turnsCount;

public:
    Inductor(T* newInductance, T* newResistance, int newTurnsCount);
    ~Inductor();
    void printInfo();
};

#endif