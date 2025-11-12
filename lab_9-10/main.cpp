#include <iostream>
#include <vector>
#include <memory>
#include "ram.h"
#include "logicIc.h"

using namespace std;

int main() {
    vector<unique_ptr<Circuit>> circuits;

    circuits.push_back(make_unique<Circuit>(100, "Test IC"));
    circuits.push_back(make_unique<Ram>(100, "RAM", 8));
    circuits.push_back(make_unique<LogicIc>(100, "AND IC", "AND"));

    for (auto &c : circuits) {
        c->showInfo();
    }

    return 0;
}
