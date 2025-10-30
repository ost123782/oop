#include <iostream>
#include <vector>
#include <memory>
#include "inductor.h"

using namespace std;


int main() {
    InductorsManager myInductors;

    myInductors.addInductor();
    myInductors.addInductor();
    myInductors.printInfo();
    myInductors.editInductor(0);
    myInductors.printInfo();

    myInductors.swapInductros(1, 0);
    myInductors.printInfo();

    myInductors.removeInductor(1);
    myInductors.printInfo();

    myInductors.clearInductors();
    myInductors.printInfo();

    return 0;
}
