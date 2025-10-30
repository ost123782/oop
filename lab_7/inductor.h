#ifndef INDUCTOR_H

#define INDUCTOR_H

#include <iostream>
#include <vector>

using namespace std;

struct inductorUnit {
    float inductance;
    float resistance;
    int turnsCount;
};


class InductorsManager {
public:
    void printInfo();
    void addInductor();
    void insertInductor(int insertId);
    void removeInductor(int inductorId);
    void clearInductors();
    void editInductor(int inductorId);
    void swapInductros(int firstInductor, int secondInductor);
    InductorsManager();
    ~InductorsManager();

private:
    vector<inductorUnit> inductors;
    inductorUnit createCheckedUserInductor();
};

#endif