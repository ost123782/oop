#include <iostream>
#include <tuple>
#include <array>
#include <cmath>
#include "inductor.h"

using namespace std;

#define PI 3.14159

void InductorsManager::printInfo() {
    for (int i = 0; i < inductors.size(); i++) {
        cout << "Inductor #" << i+1 << 
        " inductance " << inductors[i].inductance 
        <<", resistance " << inductors[i].resistance 
        <<", turns count " << inductors[i].turnsCount
        << endl;
    }
}

void InductorsManager::addInductor() {
    inductors.push_back(createCheckedUserInductor());
}

void InductorsManager::editInductor(int inductorId) {
    cout << "Editing inductor..." << endl;

    if (inductorId < 0 || inductorId >= inductors.size()) {
        cout << "Inductor's id can't be lower then 0 and inductor need to be created!" << endl;
        return;
    }

    inductorUnit newInductor = createCheckedUserInductor();

    insertInductorValues(
        inductors[inductorId], 
        newInductor.inductance, 
        newInductor.resistance, 
        newInductor.turnsCount
    );
}

void InductorsManager::insertInductor(int insertId) {
    if (insertId < 0 || insertId > inductors.size()) {
        cout << "Insert id can't be lower then 0 and inductor need to be created!" << endl;
        return;
    }

    inductors.insert(inductors.begin() + insertId, createCheckedUserInductor());
}

void InductorsManager::removeInductor(int inductorId) {
    cout << "Removing inductor..." << endl;
    
    if (inductorId < 0 || inductorId >= inductors.size()) {
        cout << "Inductor's id can't be lower then 0 and inductor need to be created!" << endl;
        return;
    }

    inductors.erase(inductors.begin() + inductorId);
}

void InductorsManager::clearInductors() {
    cout << "Clearing inductors..." << endl;

    inductors.clear();
}

void InductorsManager::swapInductros (int firstInductor, int secondInductor) {
    cout << "Swappig inductors..." << endl;

    if (
        firstInductor < 0 || firstInductor >= inductors.size() ||
        secondInductor < 0 || secondInductor >= inductors.size()
    ) {
        cout << "Inductor's id can't be lower then 0 and inductor need to be created!";
        return;
    }

    inductorUnit tempInductor = inductors[firstInductor];
    inductors[firstInductor] = inductors[secondInductor];
    inductors[secondInductor] = tempInductor;
}

InductorsManager::InductorsManager () {
    cout << "This is constructor of InductorsManager" << endl;
}

InductorsManager::~InductorsManager () {
    cout << "BOOM!" << endl;
}

inductorUnit InductorsManager::createCheckedUserInductor() {
    inductorUnit newInductor;
    bool isValid = false;

    while (!isValid) {
        cout << "Enter inductor's params (inductance, resistance, turns count) \t";
        cin >> newInductor.inductance >> newInductor.resistance >> newInductor.turnsCount;

        if 
        (
            newInductor.inductance <= 0 || 
            newInductor.resistance <= 0 || 
            newInductor.turnsCount <= 0
        ) 
        {
            cout << "Values my be greater then 0!" << endl;
            continue;
        }
        isValid = true;
    }

    return newInductor;
}

void InductorsManager::insertInductorValues
    (
        inductorUnit &inductor,         
        float inductance, 
        float resistance, 
        int turnsCount
    ) {

    inductor.inductance = inductance;
    inductor.resistance = resistance;
    inductor.turnsCount = turnsCount;
}