#include <iostream>
#include "inductor.h"

using namespace std;

int main() {
    cout << ">>> Test 1: Generic (int)" << endl;
    Inductor<int> intInductor(10, 50, 100);
    intInductor.printInfo();
    cout << endl;

    cout << ">>> Test 2: Full Specialization (double)" << endl;
    Inductor<double> doubleInductor(0.0015, 12.5, 200); 
    doubleInductor.printInfo();
    cout << endl;

    cout << ">>> Test 3: Partial Specialization (int*)" << endl;
    int lVal = 5;
    int rVal = 20;
    Inductor<int*> ptrInductor(&lVal, &rVal, 300);
    ptrInductor.printInfo();
    cout << endl;

    return 0;
}