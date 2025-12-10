#include <iostream>
#include <vector>
#include <memory>
#include "ram.h"
#include "logicIc.h"

using namespace std;

int main() {
    vector<unique_ptr<Circuit>> circuits;

    circuits.push_back(make_unique<Circuit>(100, "Base Circuit"));
    circuits.push_back(make_unique<Ram>(2000000, "Kingston RAM", 16));
    circuits.push_back(make_unique<LogicIc>(5000, "SN7400", "NAND Logic"));

    for (const auto& circuit : circuits) {
        circuit->showInfo();
    }

    return 0;
}
